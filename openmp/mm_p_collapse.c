#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>


int main(int argc, char* argv[]) {
    printf("entered main function!");
    int size = 1024;
    int (*matrix_A)[size] = malloc(sizeof(int[size][size]));
    int (*matrix_B)[size] = malloc(sizeof(int[size][size]));
    int (*result)[size] = malloc(sizeof(int[size][size]));



    printf("const set-up done!");
    //Initialize matrix: 
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix_A[i][j] =  rand();
            matrix_B[i][j] = rand();
            result[i][j] = 0;
        }
    }

    printf("matrix initialization done!");

    //Matrix multiplication
    double t1 = omp_get_wtime();
	omp_set_num_threads(16);
    #pragma omp parallel for collapse(3) shared(matrix_A,matrix_B,result)	
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                
                result[i][j] += matrix_A[i][k] * matrix_B[k][j];
            }
        }
    }
	

    printf("matrix multiplication done!");

    double t2 = omp_get_wtime();
    printf("%f\n", t2 - t1);

    free(matrix_A);
    free(matrix_B);
    free(result);

    return 0;
}