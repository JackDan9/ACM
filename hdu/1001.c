/**
||      Filename: A+B-Problem.c
||  
||  Description
||		Problem Description
||		Hey, welcome to HDOJ(Hangzhou Dianzi University Online Judge).
||
||		In this problem, your task is to calculate SUM(n) = 1 + 2 + 3 + ... + n.
||		 
||		Input
||		The input will consist of a series of integers n, one integer per line.
||		 
||		Output
||		For each case, output SUM(n) in one line, followed by a blank line. 
||		You may assume the result will be in the range of 32-bit signed integer.		 
||
||		Sample Input
||		1
||		100
||		 
||		Sample Output
||		1
||
||		5050
||
||
||      Version: 1.0
||      Reversion: none
||		complier: gcc
||      Created: 2016-08-26 14:10:32
||      Author: JackDan9(https://www.github.com/JackDan9) J.Dan92016@gmail.com
*/
// 1.Wrong
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int j = 0;
	int n;
	int sum;
	while(scanf("%d", &n) != EOF)
	{
		sum = 0;
		for(j=0; j<=n; j++)
		{
			sum += j;
		}
		printf("%d\n",sum);
	}
	return 0;
}
// 2.right
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int j = 0;
	int n;
	int sum;
	while(scanf("%d", &n) != EOF)
	{
		sum = 0;
		for(j=0; j<=n; j++)
		{
			sum += j;
		}
		printf("%d\n\n",sum);
	}
	return 0;
}

 