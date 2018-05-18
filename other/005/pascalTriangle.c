#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 100

int main(int agrc, char* argv)
{
    int i;
    int j;
    int num;
    long long arr[MAXLEN][MAXLEN];
    printf("Please input integer array length of num: \n");
    scanf("%d", &num);
    for (i = 0; i < num; i++)
    {
        arr[i][0] = 1;
    }
    for (i = 1; i < num; i++)
    {
        arr[i][i] = 1;
    }
    for (i = 2; i < num; i++) 
    {
        for (j = 1; j < i; j++)
        {
            arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
        }
    }
    printf("The pascal triangle numbers: \n");
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num; j++)
        {
            printf("%4lld", arr[i][j]);
        }
        printf("\n");
    }
}