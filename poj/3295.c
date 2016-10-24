/**
||		
||		Filename: Tautology.c
||	Description
||		WFF 'N PROOF is a logic game played with dice. Each die has six faces representing some subset of the possible symbols K, A, N, C, E, p, q, r, s, t. A Well-formed formula (WFF) is any string of these symbols obeying the following rules: 
||		p, q, r, s, and t are WFFs 
||		if w is a WFF, Nw is a WFF 
||		if w and x are WFFs, Kwx, Awx, Cwx, and Ewx are WFFs. 
||		The meaning of a WFF is defined as follows: 
||		p, q, r, s, and t are logical variables that may take on the value 0 (false) or 1 (true). 
||		K, A, N, C, E mean and, or, not, implies, and equals as defined in the truth table below. 
||		A tautology is a WFF that has value 1 (true) regardless of the values of its variables. For example, ApNp is a tautology because it is true regardless of the value of p. On the other hand, ApNq is not, because it has the value 0 for p=0, q=1. 
||		You must determine whether or not a WFF is a tautology. 
||
||	Input
||		Input consists of several test cases. Each test case is a single line containing a WFF with no more than 100 symbols. A line containing 0 follows the last case. 
||	Output
||		For each test case, output a line containing tautology or not as appropriate. 
||	Sample Input
||		ApNp
||		ApNq
||		0
||	Sample Output
||		tautology
||		not
||
||		Version: 1.0
||		Reversion: none
||		Created: 25/09/2016 13:26
||		Author: JackDan(https://www.github.com) J.Dan92016@gmail.com
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char a[105];
int result, use[7],usenum,b[105];
void init() 
{
	result = 1;
	usenum = 0;
	memset(use,-1,sizeof(use));
}
void isuse()
{
	int i, j;
	for(i=0; i<strlen(a); i++)
	{
		if(a[i]>90)
		{
			if(use[a[i]-'p']==-1)
				usenum++;
			use[a[i]-'p']=0;
		}
	}
}
int next(int x)
{
	int i, j;
	for(i=x; i<5; i++)
		if(use[i]!=-1)
			break;
		return 1;
}
void add()
{
	int i, j;
	i=next(0);
	use[i]++;
}
void create()
{
	int i, j;
	i=next(0);
	while(i<5)
	{
		if(use[i] == 2)
		{
			use[i] = 0;
			i = next(i+1);
			if(i<5)
				use[i]++;
		}
		else 
			break;
	}
}
int estimate()
{
	int i, j, pp=0;
	int res;
	int ta, tb;
	for(i=strlen(a)-1; i>=0; i--)
	{
		if(a[i]>90)
			b[pp++]=use[a[i]-'p'];
		else 
		{
			switch(a[i])
			{
				case'K':
						ta=b[--pp];
						tb=b[--pp];
						b[pp++]=ta&&tb;
						break;
				case'A':
						ta=b[--pp];
						tb=b[--pp];
						b[pp++]=ta|tb;
						break;
				case'C':
						ta=b[--pp];
						tb=b[--pp];
						b[pp++]=(!tb)|ta;
						break;
				case'E':
						ta=b[--pp];
						ta=b[--pp];
						b[pp++]=(ta&tb)|(!(ta|tb));
						break;
				case'N':
						ta=b[--pp];
						b[pp++]=!ta;
						break;
				default:
						break;
			}
		}
	}
	return b[0];
}
int main()
{
	int i, j;
	while(scanf("%s", a)!=EOF&&a[0]!='0')
	{
		init();
		isuse();
		for(i=0; i<pow(2, (double)usenum); i++)
		{
			create();
			if(!estimate())
			{
				result=0;
				break;
			}
			add();
		}
		if(result)
			printf("tautology\n");
		else
			printf("not\n");
	}
	return 0;
}
