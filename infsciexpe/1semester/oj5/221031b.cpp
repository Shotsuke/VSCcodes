#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#define int long long
using namespace std;
void clear(long long a[])
{
    for (int i = 0; i < 50; i++)
        a[i] = 0;
}
signed main()
{
    long long n, q, x, y, reqst, posi = 1, ans = 0;

    long long a[50] = {0};
    long long req[50] = {0};
    scanf("%lld%lld", &n, &q);
    for (long long i = 1; i <= n; i++)
    {
        scanf("%lld", &x);
        y = -1;
        while (x)
        {
            y++;
            x = x >> 1;
        }
        a[y]++;
    }
    /*
      for (long long i = 0; i <= n; i++)
      {
        printf("%lld\n", a[i]);
      }
    */
    for (long long i = 1; i <= q; i++)
    {
        scanf("%lld", &reqst);
        long long reqpos = -1;
        ans = 0;
        clear(req);
        while (reqst > 0)
        {
            reqpos++;
            req[reqpos] = (reqst & 1);
            reqst = (reqst >> 1);
        }

        for (int k = reqpos; k > 0; k--)
        {
            if (a[k] < req[k])
            {
                req[k] -= a[k];
                ans += a[k];
                req[k - 1] += 2 * req[k];
            }
            else
            {
                ans += req[k];
            }
        }
        if (a[0] < req[0])
        {
            printf("-1\n");
        }
        else
        {
            printf("%lld\n", ans + req[0]);
        }
    }
    return 0;
}