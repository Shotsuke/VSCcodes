#include <iostream>
#include <stdio.h>
#include <map>
#include <algorithm>
#define N 200005
using namespace std;
// Kakaa!!
long long a[200005], b[200005], indx[200005];
bool cmp(long long x, long long y)
{
    if (a[indx[x]] != a[indx[y]])
        return a[indx[x]] < a[indx[y]];
    else
        return b[indx[x]] > b[indx[y]];
}
signed main()
{

    long long n, suma = 0, sumb = 0, sum = 0;
    scanf("%lld", &n);

    for (long long i = 1; i <= n; i++)
    {
        scanf("%lld%lld", &a[i], &b[i]);
        indx[i] = i;
    }
    sort(indx + 1, indx + n + 1, cmp);
    long long pa = 1, pb = 0;
    // pa为当前在a机子的应测试的人 ，  pb为当前在b机子的应测试的人
    while (pb <= n)
    {
        if (pa == n + 1)
        { // 机子a刷完了人
            sum += b[indx[pb]];
            pb++;
        }
        else if (b[indx[pb]] > 0)
        { // b机子还有人能刷，此时两台机子同时刷人
            if (a[indx[pa]] < b[indx[pb]])
            {
                sum += a[indx[pa]];
                b[indx[pb]] -= a[indx[pa]];
                a[indx[pa]] = 0;
                pa++;
            }
            else if (a[indx[pa]] > b[indx[pb]])
            {
                sum += b[indx[pb]];
                a[indx[pa]] -= b[indx[pb]];
                b[indx[pb]] = 0;
                if (pb + 1 < pa)
                    pb++;
            }
            else
            {
                sum += a[indx[pa]];
                a[indx[pa]] = b[indx[pb]] = 0;
                pa++;
                pb++;
            }
        }
        else if (pa == pb + 1 && b[indx[pb]] == 0)
        { // 机子b无人可刷，机子a单刷
            sum += a[indx[pa]];
            a[indx[pa]] = 0;
            pa++;
            pb++;
        }
    }

    printf("%lld", sum);

    return 0;
}
