# CISC372 Final Presentation
## Introduction
This repositories contains:  
- OpenMP C code that parallelize matrix multiplication.  

- OpenACC C code that parallelize matrix multiplication.    

- Performance Analysis.  

## Requirements

Hardware:   

- Bridges2(https://www.psc.edu/resources/bridges-2/)

Compiler: 

- To load nvhpc compiler: 'module load nvhpc/21.7'.     
  
- To load gcc compiler: 'module load gcc/10.2'.   

NVIDIA Visual Profiler:    
- NVIDIA Nsight Systems(https://developer.nvidia.com/nsight-systems).   

- NVIDIA Nsight Compute(https://developer.nvidia.com/nsight-compute)


## Installation(example)
OpenMP(multicore):

For GCC:

1.module load gcc/10.2

2.gcc mm_s.c -fopenmp -o parallel_gcc

For NVHPC(NVC):

1.module load nvhpc/21.7

2.nvc -acc -gpu=cc70 -Minfo=accel mm_p.c -o paralle_nvc

OpenACC:

CPUs:

1.module load nvhpc/21.7

2.nvc -acc -ta=multicore -Minfo=accel mm_acc.c -o mm_acc

GPUs:

1.module load nvhpc/21.7

2.nvc -acc -gpu=cc70 -Minfo=accel mm_acc.c -o mm_acc


## Maintainers
Xinyi Sun(sunxinyi0501) - Performance Analysis.       

Fanchao Meng(fanchaomeng) - OpenACC parallelization.      

Ribo Yuan(riboyuan99) - OpenMP parallelization
