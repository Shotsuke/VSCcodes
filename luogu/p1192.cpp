#include <iostream>
#include <stdio.h>
#include <cmath>
#define MOD 100003
using namespace std;

long long jianzhi[100005] = {0};
long long taijie(long long n, long long k)
{
    if (jianzhi[n] == 0)
    {
        if (n <= k)
        {
            jianzhi[n] = 1;
            for (int i = 1; i <= n - 1; i++)
            {
                jianzhi[n] *= 2;
                jianzhi[n] %= MOD;
            }
        }
        else
        {
            for (int i = 1; i <= k; i++)
            {
                jianzhi[n] += taijie(n - i, k);
                jianzhi[n] %= MOD;
            }
        }
    }
    return jianzhi[n];
}
signed main()
{
    long long n, k;
    cin >> n >> k;
    printf("%lld", taijie(n, k));
    return 0;
}