/**
||      Filename: A+B-Problem.c
||  
||  Description
||		Problem Description
||		The highest building in our city has only one elevator. A request list is made up with N positive numbers. The numbers denote at which floors the elevator will stop, in specified order. It costs 6 seconds to move the elevator up one floor, and 4 seconds to move down one floor. The elevator will stay for 5 seconds at each stop.
||
||		For a given request list, you are to compute the total time spent to fulfill the requests on the list. The elevator is on the 0th floor at the beginning and does not have to return to the ground floor when the requests are fulfilled.		 
||
||		Input
||		There are multiple test cases. Each case contains a positive integer N, followed by N positive numbers. All the numbers in the input are less than 100. A test case with N = 0 denotes the end of input. This test case is not to be processed.
||		 
||
||		Output
||		Print the total time on a single line for each test case. 
||		 
||		Sample Input
||		1 2
||		3 2 3 1
||		0		 
||
||		Sample Output
||		17
||		41
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
	int n,m,s,t; 
	while(scanf("%d", &n) != EOF)
	{
		if(n)
		{
			s=n*5;t=0;
			while(n--)
			{	
				scanf("%d", &m);
				if((m-t) > 0)
					s = s + (m-t)*6;
				if((m-t) < 0)
					s = s + (t-m)*4;
				t=m;
			}
			printf("%d\n", s);
		}
		else 
		{
			break;
		}
	}
}