/**
||		Filename: Quick_Change.c
||
||	Description:
||		J.P. Flathead’s Grocery Store hires cheap labor to man the checkout stations. The people he hires (usually high school kids) often make mistakes making change for the customers. Flathead, who’s a bit of a tightwad, figures he loses more money from these mistakes than he makes; that is, the employees tend to give more change to the customers than they should get. 
||		Flathead wants you to write a program that calculates the number of quarters ($0.25), dimes ($0.10), nickels ($0.05) and pennies ($0.01) that the customer should get back. Flathead always wants to give the customer’s change in coins if the amount due back is $5.00 or under. He also wants to give the customers back the smallest total number of coins. For example, if the change due back is $1.24, the customer should receive 4 quarters, 2 dimes, 0 nickels, and 4 pennies.
||	Input
||		The first line of input contains an integer N which is the number of datasets that follow. Each dataset consists of a single line containing a single integer which is the change due in cents, C, (1 ≤ C ≤ 500).
||	Output
||		For each dataset, print out the dataset number, a space, and the string:
||		Q QUARTER(S), D DIME(S), n NICKEL(S), P PENNY(S)
||		Where Q is he number of quarters, D is the number of dimes, n is the number of nickels and P is the number of pennies.
||	Sample Input
||		3
||		124
||		25
||		194
||	Sample Output
||		1 4 QUARTER(S), 2 DIME(S), 0 NICKEL(S), 4 PENNY(S)
||		2 1 QUARTER(S), 0 DIME(S), 0 NICKEL(S), 0 PENNY(S)
||		3 7 QUARTER(S), 1 DIME(S), 1 NICKEL(S), 4 PENNY(S)
||
||		Version: 1.0
||		Reversion: none
||		Created: 2015-06-14 11:22:26
||		Author: JackDan9(https://www.github.com/JackDan9) J.Dan92016@gmmail.com 
*/
#include<stdio.h>
int main()
{
	int n,m;
	scanf("%d",&n);
	for(m=1;m<=n;m++)
	{
		int C;
		int i,j,k,t;
		int Q=25,D=10,N=5,P=1;
		scanf("%d",&C);
		i=C/Q;
		j=(C%Q)/D;
		k=((C%Q)%D)/N;
		t=(((C%Q)%D)%N)/P;
		printf("%d %d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)\n",m,i,j,k,t);
	}
}
