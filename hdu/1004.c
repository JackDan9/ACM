/**
||      Filename: A+B-Problem.c
||  
||  Description
||		Problem Description
||		Contest time again! How excited it is to see balloons floating around. 
||		But to tell you a secret, the judges' favorite time is guessing the most popular problem. 
||		When the contest is over, they will count the balloons of each color and find the result.
||
||		This year, they decide to leave this lovely job to you. 		 
||
||		Input
||		Input contains multiple test cases. Each test case starts with a number N (0 < N <= 1000) 
||		-- the total number of balloons distributed. The next N lines contain one color each. 
||		The color of a balloon is a string of up to 15 lower-case letters.
||
||		A test case with N = 0 terminates the input and this test case is not to be processed.		 
||
||		Output
||		For each case, print the color of balloon for the most popular problem on a single line. 
||		It is guaranteed that there is a unique solution for each test case.		 
||
||		Sample Input
||		5
||		green
||		red
||		blue
||		red
||		red
||		3
||		pink
||		orange
||		pink
||		0
||		 
||		Sample Output
||		red
||		pink
||
||      Version: 1.0
||      Reversion: none
||		complier: gcc
||      Created: 2016-08-26 15:11:22
||      Author: JackDan9(https://www.github.com/JackDan9) J.Dan92016@gmail.com
*/
#include <stdio.h>
#include <string.h>
int main() 
{
	int i, j, t, n, max, num[1000];
	char color[1000][16];
	while(scanf("%d", &n)!=EOF)
	{
		if(n)
		{
			num[0] = 0;
			scanf("%s", color[0]);
			for(i=1; i < n; i++)
			{
				num[i] = 1;
				scanf("%s", color[i]);
				for(j=0; j<i;j++)
				{
					if(strcmp(color[i], color[j]) == 0)
						num[i] = num[i] + 1;
				}
			}
			max=0;
			t=0;
			for(i=1; i<n; i++)
			{
				if(max < num[i])
				{
					max=num[i];
					t=i;
				}
			}
			printf("%s\n",color[t]);
		}
	}	
}
