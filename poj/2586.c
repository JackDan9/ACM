/**
||	Filename: Y2K-Account--Bug.c
||	Description:
||		Accounting for Computer Machinists (ACM) has sufferred from the Y2K bug and lost some vital data for preparing annual report for MS Inc. 
||		All what they remember is that MS Inc. posted a surplus or a deficit each month of 1999 and each month when MS Inc. posted surplus, the amount of surplus was s and each month when MS Inc. posted deficit, the deficit was d. They do not remember which or how many months posted surplus or deficit. MS Inc., unlike other companies, posts their earnings for each consecutive 5 months during a year. ACM knows that each of these 8 postings reported a deficit but they do not know how much. The chief accountant is almost sure that MS Inc. was about to post surplus for the entire year of 1999. Almost but not quite. 
||		Write a program, which decides whether MS Inc. suffered a deficit during 1999, or if a surplus for 1999 was possible, what is the maximum amount of surplus that they can post.
||	Input:
||		Input is a sequence of lines, each containing two positive integers s and d.
||	Output:
||		For each line of input, output one line containing either a single integer giving the amount of surplus for the entire year, or output Deficit if it is impossible.
||
||		Version: 1.0
||		Created: 26/09/2016 15:32
||		Revision: none
||		Compiler: gcc
||				
||			Author: JackDan9(https://github.com/JackDan9), J.Dan92016@gmail.com
*/


#include <stdio.h>
int main()
{
	int s;
	int d;
	int profit;
	while(scanf("%d %d", &s, &d) != EOF)
	{
		int profit = -1;
		if(4*s < d) 
			profit=10*s - 2*d;
		else if(3*s < 2*d)
			profit=8*s - 4*d;
		else if(2*s < 3*d)
			profit=6*s - 6*d;
		else if(s < 4*d)
			profit=3*s -9*d;
		if(profit < 0) 
			printf("Deficit\n");
		else 
			printf("%d\n", profit);
	}
}