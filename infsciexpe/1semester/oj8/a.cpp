#include <iostream>
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <algorithm>
using namespace std;
long long a[1000005];
long long ans[1000005];
long long indx[1000005];
bool cmp(long long x, long long y)
{

    return a[x] > a[y] || a[x] == a[y] && x < y;
}
signed main()
{
    long long t, p, n, pointer = 0;
    long long sum;
    long double ave = 0.0;
    scanf("%lld", &t);
    for (int i = 1; i <= t; i++)
    {
        scanf("%lld%lld", &p, &n);
        for (int j = 1; j <= n; j++)
            indx[j] = j;
        sum = 0;

        for (int j = 1; j <= n; j++)
        {
            scanf("%lld", &a[j]);
            sum += a[j];
        }
        if (sum < p)
            printf("IMPOSSIBLE\n");
        else
        {
            sort(indx + 1, indx + 1 + n, cmp);
            ave = p / (1.0 * n);
            bool flag = false;
            for (int k = n; k >= 1; k--)
            {
                if (ave - a[indx[k]] >= 1e-7) // 可能要修改
                {
                    ans[indx[k]] = a[indx[k]];
                    p -= ans[indx[k]];
                }
                else
                {
                    ans[indx[k]] = (long long)ave;
                    p -= ans[indx[k]];
                    if (a[indx[k]] > ans[indx[k]] && flag == false)
                    {
                        pointer = k;
                        flag = true;
                        // pointer表征最后一个仍然有剩余钱的洞穴。
                    }
                }
            }
            long long u = 1;
            while (p > 0)
            {
                ans[indx[u]]++;
                p--;
                u++;
                if (ans[indx[u - 1]] == a[indx[u - 1]])
                {
                    for (int v = u; v <= pointer && p > 0; v++)
                    {
                        ans[indx[v]]++;
                        p--;
                    }
                    pointer = u - 2;
                    u = 1;
                }
                else if (u > pointer)
                    u = 1;
            }
            for (int k = 1; k < n; k++)
            {
                printf("%lld ", ans[k]);
            }
            printf("%lld\n", ans[n]);
        }
    }
}