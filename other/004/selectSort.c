#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 10000

int main(int agrc, char* argv)
{
    int arr[MAXLEN];
    int i;
    int j;
    int k;
    int temp;
    int num;
    printf("Please input a number of num: \n");
    scanf("%d", &num);
    printf("Please input num groups of number: \n");
    for (i = 1; i <= num; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\n");
    for (i = 1; i <= num; i++) 
    {
        k = i;
        for (j = i+1; j <= num; j++)
        {
            if (arr[j] < arr[k])
            {
                k = j;
            }
        }
        if (i != k) 
        {
            temp = arr[i];
            arr[i] = arr[k];
            arr[k] = temp;
        }
    }
    printf("The sorted numbers: \n");
    for (i = 1; i <= num; i++)
    {
        printf("%d", arr[i]);
    }
}