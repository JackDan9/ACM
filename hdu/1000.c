/**
||      Filename: Sum-Problem.c
||  
||  Description
||	 
||		Problem Description
||		Calculate A + B.
||		 
||
||		Input
||		Each line will contain two integers A and B. Process to end of file.
||		 
||		Output
||		For each case, output A + B in one line.		 
||
||		Sample Input
||		1 1
||		 
||		Sample Output
||		2
||
||      Version: 1.0
||      Reversion: none
||		complier: gcc
||      Created: 2016-08-26 14:01:38
||      Author: JackDan9(https://www.github.com/JackDan9) J.Dan92016@gmail.com
*/
#include <stdio.h>
int main()
{
	int A=0,B=0;
	while(scanf("%d %d", &A, &B)!=EOF)
		printf("%d\n", A+B);
}