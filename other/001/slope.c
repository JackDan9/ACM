/**
*
* title: slope
*
* description: the slope of a curva
* 
* tags: least_squares
* 
* examples:  
*     //x[0] = 0.1; x[1] = 0.3; x[2] = 0.4; x[3] = 0.55; x[4] = 0.7; x[5] = 0.8; x[6] = 0.95;
*     //y[0] = 15; y[1] = 18; y[2] = 19; y[3] = 21; y[4] = 22.6; y[5] = 23.8; y[6] = 26;
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

/**
*
* average 
*
*/

float average(int n, float *x)
{
    int i;
    float av;
    av = 0;
    for (i = 0; i < n; i++) 
    {
        av += *(x + i);
    }
    av = av/n;
    return(av);
}

/**
*
* number_square_sum
*
*/
float spfh(int n, float *x)
{
    int i;
    float a;
    a = 0;
    for (i = 0; i < n; i++)
    {
        a += (*(x+i))*(*(x+i));
    }
    return(a);
}

/**
*
* number_sum_square
*
*/
float shpf(int n, float *x)
{
    int i;
    float a;
    float b;
    a = 0;
    for (i = 0; i < n; i++)
    {
        a = a + *(x+i);
    }
    b = a * a/n;
    return(b);
}

/**
* 
* multiply two numbers and then add them
*
*/
float dcj(int n, float *x, float *y)
{
    int i;
    float a;
    a = 0;
    for (i = 0; i < n; i++)
    {
        a += (*(x+i)) * (*(y+i));
    }
    return (a);
}

/**
*
* add two numbers and then multiply them
*
*/
float djc(int n, float *x, float *y)
{
    int i;
    float a = 0;
    float b = 0;
    for (i = 0; i < n; i++)
    {
        a = a + *(x + i);
        b = b + *(y + i);
    }
    a = a*b/n;
    return(a);
}

/**
*
* coefficient a in the least squares result
*
*/
float xsa(int n, float *x, float *y)
{
    float a;
    float b;
    float c;
    float d;
    float e;
    a = spfh(n, x);
    b = shpf(n, x);
    c = dcj(n, x, y);
    d = djc(n, x, y);
    e = (c - d)/(a - b);
    return(e);
}

/**
*
* sum 
*
*/
float he(int n, float *y)
{
    int i;
    float a;
    a = 0;
    for (i = 0; i < n; i++)
    {
        a = a + *(y + i);
    }
    return(a);
}

/**
*
* coefficient b in the least squares result
*
*/
float xsb(int n, float *x, float *y, float a) {
    float b;
    float c;
    float d;
    b = he(n, y);
    c = he(n, x);
    d = (b-a*c)/n;
    return(d);
}

int main(int argc, char* argv) {
    int n;
    int i;
    float *x;
    float *y;
    float a;
    float b;
    printf("Please input valid numeric groups n: ");
    scanf("%d", &n);
    printf("n = %d\n", n);
    x = (float*)calloc(n, sizeof(float));
    if (x==NULL) 
    {
        printf("Memory allocation failed!");
        exit(1);
    }
    y = (float*)calloc(n, sizeof(float));
    if (y==NULL) 
    {
        printf("Memory allocation failed!");
        exit(1);
    }
    printf("Please input x: ");
    for (i = 0; i < n; i++) 
    {
        scanf("%f", x+i);
    }
    printf("Please input y(Please note that the value one by one corresponds to X): ");
    for (i = 0; i < n; i++)
    {
        scanf("%f", y+i);
    }
    for (i = 0; i < n; i++)
    {
        printf("x[%d] = %5.4f ", i, *(x + i));
        printf("y[%d] = %5.4f\n", i, *(y + i));
    }
    a = xsa(n, x, y);
    b = xsb(n, x, y, a);
    printf("The linear equation obtained by least squares function is: \n");
    printf("f(x) = %5.4fx + %5.4f\n", a, b);
}