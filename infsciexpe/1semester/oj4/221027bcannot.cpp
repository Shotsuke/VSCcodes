#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int main()
{
    long long t, x, y, z, tot = 1;
    int a[40], b[40], c[40];
    scanf("%lld", &t);
    for (long long i = 1; i <= t; i++)
    {
        scanf("%lld%lld%lld", &x, &y, &z);
        for (int j = 0; j < 40; j++) // clear
        {
            a[j] = b[j] = c[j] = 0;
        }
        if (a > b)
            swap(a, b);
        for (int j = 0; j < 40; j++) // initialize
        {
            a[j] = x & 1;
            b[j] = y & 1;
            c[j] = z & 1;
            x = x >> 1;
            y = y >> 1;
            z = z >> 1;
        }
        int pa = 0;
        for (int j = 39; j >= 0; j--) // search for the first 1
        {
            if (a[j] == 1)
            {
                pa = j;
                break;
            }
        }
        int k = 0;
        while (k <= pa)
        {
            k++;
        }
    }
    return 0;
}