#include <iostream>
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <algorithm>
using namespace std;
double ang[100005];
double angcul(long long x, long long y);
int main()
{
    long long n, j = 1, i = 1, x, y;
    long long ans = 0;
    scanf("%lld", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%lld%lld", &x, &y);
        ang[i] = angcul(x, y);
    }
    sort(ang + 1, ang + n + 1);
    i = 1;
    ans = n * (n - 1) * (n - 2) / 6;
    for (; i <= n; i++)
    {
        while (ang[j % n + 1] + j / n * 2 * M_PI - ang[i] < M_PI)
        {
            j++;
        }
        ans = ans - (j - i) * (j - i - 1) / 2;
    }
    printf("%lld", ans);
    /*for (int i = 1; i <= n; i++)
    {
        printf("%lf\n", ang[i]);
    }*/
}
double angcul(long long x, long long y)
{
    if (x == 0 && y > 0)
        return M_PI / 2;
    else if (x == 0 && y < 0)
        return M_PI * 3 / 2;
    else if (y == 0 && x > 0)
        return 0.0;
    else if (y == 0 && x < 0)
        return M_PI;
    else if (x > 0 && y > 0)
        return atan(y * 1.0 / x);
    else if (x < 0 && y > 0)
        return M_PI - atan(y * 1.0 / (-x));
    else if (x < 0 && y < 0)
        return M_PI + atan((-y) * 1.0 / (-x));
    else
        return 2 * M_PI - atan((-y) * 1.0 / x);
}