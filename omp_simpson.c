// C code to implement SIMPSONS RULE
// use -> gcc program_name.c -lm


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<omp.h>
#include<mpi.h>

int main(int argc, char* argv[])
{
	
	float x0 = 0, ans=0,s1=0,s2=0,sum=0;
	float xn = 3.1418,x1=0,x2=0;
                                     // Number of steps
	int n = pow(2,20);
	int i=0;
	int thread_count;
        thread_count = strtol(argv[1], NULL, 10);

	clock_t start =clock();                  // width of every step
	float h = (xn-x0)/n;
	
	
	 #  pragma omp parallel for schedule(static) default(none) \
      shared(x0, h, n) private(i,x1,x2) \
     reduction(+: s1,s2) num_threads(thread_count)
      

          for(i=1;i<=n-1;i++){
            
            if(i%2==0){
               x1=sin(x0+i*h);
               s1+=x1;
            }else{
               x2=sin(x0+i*h);
               s2+=x2;
            }
         }
         
          s1=h/3*(x0+xn+4*s2+2*s1);
          
          
          clock_t end = clock();
          float exec = end-start;
          
          printf("\n****SIMPSONS RULE******\n");
          printf("\n OPEN_MP sin(x) in [0,pie] is %f\n",s1);
          printf("Time taken to calculate %f\n",exec);
         
     
 
 
  return 0;
}

