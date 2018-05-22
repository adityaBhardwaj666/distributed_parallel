// C code to implement SIMPSONS RULE
// use -> gcc program_name.c -lm


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


int main()
{
	
	float x0 = 0, ans=0,s1=0,s2=0,sum=0;
	float xn = 3.1418;
                                     // Number of steps
	int n = pow(2,20);
	int i=0;
		      
	clock_t start =clock();                  // width of every step
	float h = (xn-x0)/n;
	
	if(n%2==0){
          for(i=1;i<=n-1;i++){
            
            if(i%2==0)  
               s1=s1+sin(x0+i*h);
            else
               s2=s2+sin(x0+i*h);
            
            }
         
          sum=h/3*(x0+xn+4*s2+2*s1);
          clock_t end = clock();
          float exec = end-start;
          
          printf("\n****SIMPSONS RULE******\n");
          printf("\n sin(x) in [0,pie] is %f\n",sum);
          printf("Time taken to calculate %f\n",exec);
         
         }
       else
         printf("the rule is not appliciable");
 
  return 0;
}

