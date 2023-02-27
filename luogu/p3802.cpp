#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int main()
{
    long long a[7], sum = 0;
    double ans = 1.0;
    for (int i = 0; i < 7; i++)
    {
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    for (int i = 0; i < 6; i++)
    {
        ans *= a[i];
        ans /= (sum - i);
    }

    ans *= 1.0 * 7 * 6 * 5 * 4 * 3 * 2 * 1;
    ans *= a[6];
    printf("%.3lf", ans);
    return 0;
}