#include <iostream>
#include <stdio.h>
using namespace std;

int n;
double s[25];
double a[25];
double p, q;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lf%lf", &s[i], &a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        p += s[i] * a[i];
    }
    p /= 20.0;
    for (int i = 1; i <= n; i++)
    {
        q += s[i];
    }
    printf("%.2lf", p / q);
    return 0;
}