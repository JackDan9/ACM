/**
||		Filename: Radar-Installation.c
||	 Description:
||		Assume the coasting is an infinite straight line. Land is in one side of coasting, sea in the other. Each small island is a point locating in the sea side. And any radar installation, locating on the coasting, can only cover d distance, so an island in the sea can be covered by a radius installation, if the distance between them is at most d. 
||
||		We use Cartesian coordinate system, defining the coasting is the x-axis. The sea side is above x-axis, and the land side below. Given the position of each island in the sea, and given the distance of the coverage of the radar installation, your task is to write a program to find the minimal number of radar installations to cover all the islands. Note that the position of an island is represented by its x-y coordinates. 
||	Input:
||		The input consists of several test cases. 
||		The first line of each case contains two integers n (1<=n<=1000) and d, 
||		where n is the number of islands in the sea and d is the distance of coverage of the radar installation. 
||		This is followed by n lines each containing two integers representing the coordinate of the position of each island. 
||		Then a blank line follows to separate the cases.
||		The input is terminated by a line containing pair of zeros
||	Output:
||		For each test case output one line consisting of the test case number followed by the minimal number of radar installations needed. 
||		"-1" installation means no solution for that case.	 
||	Sample Input:
||		3 2
||		1 2
||		-3 1
||		2 1
||
||		1 2
||		0 2
||
||		0 0
||	Sample Output
||		Case 1: 2
||		Case 2: 1
||	Test Input:
||		2 5	
||		-6 3
||		-3 4
||	
||		3 3
||		-3 2
||		1 2
|| 		2 4
||
||		...
||		
||	Test Output
||		Case 1: 1
||		Case 2: -1
||
||		...
||	
||		Version: 1.0
||		Created: 26/08/2016 15:38
||		Reversion: none
||		Author: JackDan9(https://www.github.com/JackDan9) J.Dan92016@gmail.com
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 1001

int islands;
int radius;
int x[MAX];
int y[MAX];
double left[MAX];
double right[MAX];
int radars;
double radarX;
int noSolution = 0;
int caseNum = 0;

int partition(int left, int right) {
	int pivotValueX = x[left];
	int pivotValueY = y[left];
	while(left < right) {
		while(left < right && x[right] >= pivotValueX) {
			right--;
		}
		x[left] = x[right];
		y[left] = y[right];
		while(left < right && x[left] <= pivotValueX) {
			left++;
		} 
		x[right] = x[left];
		y[right] = y[left];
	}
	x[left] = pivotValueX;
	y[left] = pivotValueY;
	return left;
}
void quickSort(int left, int right) {
	if (left == right) {
		return;
	}
	int pivot;
	pivot = partition(left, right);
	partition(left, pivot-1);
	partition(pivot-1, right);
}
int main(void)
{
	int island;
	while(scanf("%d %d", &islands, &radius)!=EOF) {
		 if(islands == 0 && radius == 0) {
		 	return 0;
		 }
		 for (island = 0; island < islands; island++) {
		 	scanf("%d %d", &x[island], &y[island]);
		 	if(y[island] > radius) {
		 		noSolution = 1;
		 	}
		 }
		 if(noSolution == 1 || radius <= 0) {
		 	printf("Case %d: -1\n", ++caseNum);
		 	continue;
		 }
		 int round;
		 for(round=1; round < islands; round++) {
		 	for (island = 0; island < islands - round; island++) {
		 		if(x[island] > x[island + 1]) {
		 			int temp = x[island];
		 			x[island] = x[island+1];
		 			x[island+1] = temp;
		 			temp = y[island];
		 			y[island] = y[island+1];
		 			y[island+1] = temp;
		 		}

		 	}
		}
		for(island=0; island < islands; island++) {
			double temp = sqrt((double)(radius * radius - y[island] * y[island]));
			left[island] = x[island] - temp;
			right[island] = x[island] + temp;
		}
		radars = 1; 
		radarX = right[0];
		for(island = 1; island < islands; island++) {
			if (left[island] >radarX) {
				radars++;
				radarX = right[island];
			} 
			else if(right[island] < radarX) {
				radarX = right[island];
			}
		}
		printf("Case %d: %d\n", ++caseNum, radars);
	}
	return 0;
}