#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 10000

int main(int argc, char* argv)
{
    char temp;
    char str[MAXLEN];
    int i;
    int j;
    printf("Enter a string: \n");
    scanf("%s", str); // 也可以是gets(str); puts(str);
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    printf("Reversed string: \n");
    printf("%s", str);
}