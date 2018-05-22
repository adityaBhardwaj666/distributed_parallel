// C program to implement Trapezoidal rule
// use -> gcc program_name.c -lm 

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


int main()
{
	
	float x0 = 0, ans=0;
	float xn = 3.1418;
                                     // Number of steps
	int n = pow(2,20);
		    
	clock_t start = clock();	                       
	float h = (xn-x0)/n;               // width of every step
	float s = sin(x0)+sin(xn);
                                        // Adding middle terms in above formula
	for (int i = 0; i < n; i++)
		s += 2*sin(x0+i*h);

	ans=(h/2)*s;
	
	clock_t end = clock();
	float exec = end-start;
	
	printf("\n**** TRAPEZOIDAL RULE ****\n");
	printf("\n sin(x) in [0,pie] is %f\n",ans);
	printf("Time taken to calculate %f\n",exec);
	
	return 0;
}

