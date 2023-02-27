#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string.h>
using namespace std;
unsigned long long int a, b, p;
int x[64], y[64], ans[128];
int main()
{
    scanf("%llu%llu", &a, &b);
    p = -1;
    int t = 0;
    while (a > 0)
    {
        t = a & 1;
        p++;
        x[p] = t;
        a = a >> 1;
    }
    p = -1;
    while (b > 0)
    {
        t = b & 1;
        p++;
        y[p] = t;
        b = b >> 1;
    }
    for (int i = 0; i <= 63; i++)
    {
        if (y[i]) //乘数的第i位（0为第一位
        {
            for (int j = 0; j <= 63; j++)
            {
                if (x[j])
                    ans[i + j]++;
            }
        }
    }
    for (int i = 0; i <= 126; i++)
    {
        if (ans[i] != 0)
        {
            ans[i + 1] += ans[i] / 2;
            ans[i] = ans[i] & 1;
        }
    }
    a = 0;
    b = 0;
    p = 1;
    for (int i = 0; i <= 63; i++)
    {
        a += p * ans[i];
        p *= 2;
    }
    p = 1;
    for (int i = 64; i <= 127; i++)
    {
        b += p * ans[i];
        p *= 2;
    }
    printf("%llu %llu", b, a);
    return 0;
}