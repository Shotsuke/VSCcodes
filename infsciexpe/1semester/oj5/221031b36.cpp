#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
long long a[200005];
bool cmp(long long x, long long y)
{
    return x > y;
}
signed main()
{
    long long n, q, req, posi = 1, ans = 0;
    scanf("%lld%lld", &n, &q);
    for (long long i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + n + 1, cmp);
    /*for (long long i = 1; i <= n; i++)
    {
        printf("%lld\n", a[i]);
    }*/
    for (long long i = 1; i <= q; i++)
    {
        scanf("%lld", &req);
        posi = 1;
        ans = 0;
        while (req > 0 && posi <= n)
        {
            while (req - a[posi] < 0 && posi <= n)
                posi++;

            if (posi == n + 1)
                break;
            req -= a[posi];
            posi++;
            ans++;
        }
        if (req == 0)
        {
            printf("%lld\n", ans);
        }
        else
        {
            printf("-1\n");
        }
    }

    return 0;
}