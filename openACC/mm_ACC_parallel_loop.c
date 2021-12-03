#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#include <openacc.h>


int main(int argc, char* argv[]) {
    printf("entered main function!\n");
    int size = 1024;
    int (*matrix_A)[size] = malloc(sizeof(int[size][size]));
    int (*matrix_B)[size] = malloc(sizeof(int[size][size]));
    int (*result)[size] = malloc(sizeof(int[size][size]));



    printf("const set-up done!\n");
    //Initialize matrix:
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix_A[i][j] = rand();
            matrix_B[i][j] = rand();
            result[i][j] = 0;
        }
    }

    printf("matrix initialization done!\n");

    //Matrix multiplication
    double t1 = omp_get_wtime();
    #pragma acc parallel loop
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                result[i][j] += matrix_A[i][k] * matrix_B[k][j];
            }
        }
    }
    printf("matrix multiplication done!\n");

    double t2 = omp_get_wtime();
    printf("%f\n", t2 - t1);

    free(matrix_A);
    free(matrix_B);
    free(result);

    return 0;
}
