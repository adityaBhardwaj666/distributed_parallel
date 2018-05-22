Includes programs to calculate definte integral of Sine function from [0,pie] using 
 - Trapezium Rule
 - Simpsons 1/3 Rule
 
omp files are parallel implementation of the programs using openMP.



1) omp_trap.c and omp_simpson.c are OpenMp programs. 
   Use -lm in commands to link math function 


2) For openMP execution use :
   
   gcc -o filename -fopenmp filename.c -lm
   export OMP_NUM_THREADS=2
   ./filename argv1
   
   
3) For mpi execution (multi-core) use :

    mpicc filename.c -o filename -lm
    mpiexec -n 5 filename argv1



