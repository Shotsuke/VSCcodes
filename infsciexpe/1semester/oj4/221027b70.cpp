#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int main()
{
    long long n, x, y, z;
    long long ans = 0;
    scanf("%lld", &n);
    for (long long i = 1; i <= n; i++)
    {
        scanf("%lld%lld%lld", &x, &y, &z);
        for (long long j = 0; j <= x; j++)
        {
            for (long long k = 0; k <= y; k++)
            {
                if ((j ^ k) >= z)
                    ans++;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}