#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 10000

int main(int agrc, char *argv)
{
    int arr[MAXLEN];
    int i;
    int j;
    int num;
    int temp;
    printf("Please input num: \n");
    scanf("%d", &num);
    printf("Please input num groups: \n");
    for (i = 1; i <= num; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\n");
    for (j = 1;  j <= num - 1; j++)
    {
        for (i = 1; i <= num - j; i++)
        {
            if (arr[i] > arr[i+1])
            {
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
            
        }
    }
    printf("The sorted numbers: \n");
    for (i = 1; i <= num; i++)
    {
        printf("%d", arr[i]);
    }
}