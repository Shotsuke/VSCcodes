#include <iostream>
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <algorithm>
using namespace std;
double ang[1000005];
double angcul(int x, int y);
int main()
{
    int n, x, y, minn = 1000005;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) // scanf
    {
        scanf("%d%d", &x, &y);
        ang[i] = angcul(x, y);
    }
    sort(ang + 1, ang + n + 1);
    int i = 1, j = 1;
    for (; i <= n; i++)
    {
        while (ang[(j - 1) % n + 1] + (j - 1) / n * 2 * M_PI - ang[i] < M_PI)
        {
            j++;
        }
        minn = min(minn, j - i - 1);
    }
    printf("%d", minn);
    return 0;
}
double angcul(int x, int y)
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
        return atan((double)y * 1.0 / (double)x * 1.0);
    else if (x < 0 && y > 0)
        return M_PI - atan((double)y * 1.0 / (double)(-x) * 1.0);
    else if (x < 0 && y < 0)
        return M_PI + atan((double)(-y) * 1.0 / (double)(-x) * 1.0);
    else
        return 2 * M_PI - atan((double)(-y) * 1.0 / (double)x * 1.0);
}