#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv)
{
    int i;
    int j;
    int k;
    int n;
    long long num;
    printf("Please input the number of num: \n");
    scanf("%lld", &num);
    if (num <= 100) 
    {
        printf("Please input the justice number(>100) of num: \n");
        scanf("%lld", &num);
    } 
    printf("The daffodil number: \n");
    for (n = 100; n < num; n++)
    {
        i = n / 100;
        j = n / 10 - i * 10;
        k = n % 10;
        if (n == i*i*i + j*j*j + k*k*k) 
        {
            printf("%4lld ", n);
        }
    }
    printf("\n");
}