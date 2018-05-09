/**
* 
* title: standard_deviation
* 
* tags: avg, stdev
* 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
*
* avg function: return a average of a set of data
*
* parameters: name    type    description   
*             num[]   float   a group of numbers
*             n       int     number of elements in an array
* 
* return: type
*         float
*
*/

float avg(float num[], int n) 
{
    int i = 0;
    float sum = 0.0f; // data_sum
    for (i = 0; i < n; i++) 
    {
        sum += num[i];
    }
    return sum/n;
}

/**
* 
* stdev function: returns the standard deviation of a group of numbers
* 
* parameters: name    type    desciption
*             num[]   float   a group of numbers
*             n       int     number of elements in an array
*  
* return: type
*         float
*
*/

float stdev(float num[], int n) 
{
    int i = 0;
    float avg1 = avg(num, n);
    float sum = 0.0f;
    for(i = 0; i < n; i++) 
    {
        sum += (num[i]-avg1)*(num[i] - avg1);
    }

    return sqrt(sum/n); 
}

int main(int argc, char* argv) {
    float num[10] = {1.2f, 3.4f, 2.3f, 6.3f, 1.3f, 3.2f, 4.4f, 2.2f, 5.5f, 3.2f};
    printf("avg: %.3f\n", avg(num, 10));
    printf("stdev: %.3f\n", stdev(num, 10));
    return 0;
}