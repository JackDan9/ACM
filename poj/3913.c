/**
||		Filename: Gnome-Sequencing.c
||	Description:
||		In the book All Creatures of Mythology, gnomes are kind, bearded creatures, while goblins tend to be bossy and simple-minded. The goblins like to harass the gnomes by making them line up in groups of three, ordered by the length of their beards. The gnomes, being of different physical heights, vary their arrangements to confuse the goblins. Therefore, the goblins must actually measure the beards in centimeters to see if everyone is lined up in order. 
||		Your task is to write a program to assist the goblins in determining whether or not the gnomes are lined up properly, either from shortest to longest beard or from longest to shortest.
||	Input:
||		The input starts with line containing a single integer N, 0 < N < 30, which is the number of groups to process. Following this are N lines, each containing three distinct positive integers less than 100.
||	Output:
||		There is a title line, then one line per set of beard lengths. See the sample output for capitalization and punctuation. 
||	Sample Input:
||		3
||		40 62 77
||		88 62 77
||		91 33 18
||	Sample Output:
||		Gnomes:
||		Ordered
||		Unordered
||		Ordered
||
||		Version: 1.0
||		Reversion: none
||		Created: 2016-03-04 17:11:57
||		Author: JackDan9(https://www.github.com/JackDan9) J.Dan92016@gmmail.com 
||
*/
#include<stdio.h>
int main()
{
	int N,x,y,z,i;
	scanf("%d",&N);
	printf("Gnomes:\n");
	for(i=0; i<N; i++)
	{
	    scanf("%d %d %d",&x,&y,&z);
		if((x>y && y>z)||(x<y && y<z))  printf("Ordered\n");
		else printf("Unordered\n");
	}
}