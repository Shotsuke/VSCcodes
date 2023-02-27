#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

long long a[1000000][2];
bool isprime(long long x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
signed main()
{
    for (long long i = 0; i < 1000000; i++)
    {
        a[i][0] = 1;
        a[i][1] = 0;
    }
    long long n = 1372548;
    int pointera = 0;
    for (long long i = 2; i <= n; i++)
    {
        if (isprime(i) && n % i == 0)
        {
            pointera++;
            a[pointera][0] = i;
            while (n % i == 0)
            {
                n /= i;
                a[pointera][1]++;
            }
        }
    }
    for (long long i = 1; i <= pointera; i++)
    {
        printf("yinzi:%lld cifang:%lld\n", a[i][0], a[i][1]);
    }
}