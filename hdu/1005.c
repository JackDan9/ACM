/**
||      Filename: A+B-Problem.c
||  
||  Description
||		Problem Description
||		A number sequence is defined as follows:
||
||		f(1) = 1, f(2) = 1, f(n) = (A * f(n - 1) + B * f(n - 2)) mod 7.
||
||		Given A, B, and n, you are to calculate the value of f(n).
||		 
||		Input
||		The input consists of multiple test cases. 
||		Each test case contains 3 integers A, B and n on a single line (1 <= A, B <= 1000, 1 <= n <= 100,000,000). 
||		Three zeros signal the end of input and this test case is not to be processed.		 
||
||		Output
||		For each test case, print the value of f(n) on a single line.
||		 
||
||		Sample Input
||		1 1 3
||		1 2 10
||		0 0 0
||		 
||
||		Sample Output
||		2
||		5
||
||      Version: 1.0
||      Reversion: none
||		complier: gcc
||      Created: 2016-08-26 16:20:22
||      Author: JackDan9(https://www.github.com/JackDan9) J.Dan92016@gmail.com
*/
#include <stdio.h>
int main()
{
	int A,B,i,n;
	int f[48];
	while(scanf("%d %d %d",&A, &B, &n))
	{
		if(n && A && B)
		{
			f[1] = 1;
			f[2] = 1;
			for(i=3; i<48; i++)
			{
				f[i] = (A*f[i-1] + B*f[i-2]) % 7;
			}
			printf("%d\n",f[n%48]);
		}
		else {
			break;
		}
	}
}