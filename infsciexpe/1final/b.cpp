#include <iostream>
#include <stdio.h>
#include <cmath>
#include <stdlib.h>
#include <cstring>
#include <string.h>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
long long a[1000005];
void solve(long long n, long long tottime,
           long long *ansque, long long *anstime);
signed main()
{
    long long T, n, t, ansque = 0, anstime = 0;
    scanf("%lld", &T);
    for (int i = 1; i <= T; i++)
    {

        scanf("%lld%lld", &n, &t);
        for (int j = 1; j <= n; j++)
            scanf("%lld", &a[j]);

        solve(n, t, &ansque, &anstime);

        printf("%lld %lld\n", ansque, anstime);
    }

    return 0;
}
void solve(long long n, long long tottime,
           long long *ansque, long long *anstime)
{
    long long yilun = 0, aptr = 1;
    for (long long j = 1; j <= n; j++)
        yilun += a[j];

    tottime = (tottime - 1) % yilun + 1;

    while (tottime > a[aptr])
    {
        tottime -= a[aptr];
        aptr++;
    }

    *ansque = aptr;
    *anstime = tottime;
    return;
}