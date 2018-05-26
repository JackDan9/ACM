#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#define MAXLEN 10000

int prime(int n) 
{
    assert(n > 0);
    int i = 0;
    for (i = 2; i <= sqrt(n); i++)
    {
        if (n%i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main(int agrc, char* agrv)
{
    int i = 0;
    int count = 0;
    long long num;
    printf("please input the number of num: \n");
    scanf("%lld", &num);
    printf("The prime number between 1-num is small to large: \n");
    for (i = 2; i < num; i++)
    {
        if (prime(i))
        {
            count ++;
            printf("%4lld ", i);
        }
    }
    printf("\nThere are %d\n", count);
    return 0;
}