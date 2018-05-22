// C program to implement Trapezoidal rule
// use -> gcc program_name.c -lm 

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<omp.h>
#include<mpi.h>


int main(int argc, char* argv[])
{
	
	float x0 = 0, ans=0;
	float xn = 3.1418,s=0,x=0;
                                     // Number of steps
	int n = pow(2,20);
	int thread_count;
           thread_count = strtol(argv[1], NULL, 10);
	clock_t start = clock();	                       
	float h = (xn-x0)/n;               // width of every step
	 s = sin(x0)+sin(xn);
         int i;     
       #  pragma omp parallel for schedule(static) default(none) \
      shared(x0, h, n) private(i,x) \
     reduction(+: s) num_threads(thread_count)
                          // Adding middle terms in above formula
	for (i = 0; i < n; i++){
		x= (x0+i*h);
		s+=2*sin(x);
           }
	s=(h/2)*s;
	
	clock_t end = clock();
	float exec = end-start;
	
	printf("\n**** TRAPEZOIDAL RULE ****\n");
	printf("\n sin(x) in [0,pie] is %f\n",s);
	printf("Time taken to calculate %f\n",exec);
	
	return 0;
}

