#include <iostream>
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <cstring>
#include <string.h>
#include <algorithm>
using namespace std;
bool flg[2005][2005];
int ansx[2005], ansy[2005];
void srch(int x, int y, int n, int m, int repi, int manh);
int main()
{
    int n, m, k, x, y;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= k; i++)
    {
        scanf("%d%d", &x, &y);
        srch(x, y, n, m, i, 0);
    }
    for (int i = 1; i <= k; i++)
    {
        printf("%d %d\n", ansx[i], ansy[i]);
    }
    return 0;
}
void srch(int x, int y, int n, int m, int repi, int manh)
{
    int i = 0, j = 0;
    if (x - manh >= 1)
        i = manh;
    else
        i = x - 1;
    for (; i >= 1; i--)
    {
        if (y - (manh - i) >= 1)
        {
            if (flg[x - i][y - (manh - i)] == false)
            {
                ansx[repi] = x - i;
                ansy[repi] = y - (manh - i);
                flg[x - i][y - (manh - i)] = true;
                return;
            }
        }
        if (y + (manh - i) <= m)
        {
            if (flg[x - i][y + (manh - i)] == false)
            {
                ansx[repi] = x - i;
                ansy[repi] = y + (manh - i);
                flg[x - i][y + (manh - i)] = true;
                return;
            }
        }
    }
    if (x + manh <= n)
        j = manh;
    else
        j = n - x;
    for (i = 0; i <= j; i++)
    {
        if (y - (manh - i) >= 1)
        {
            if (flg[x + i][y - (manh - i)] == false)
            {
                ansx[repi] = x + i;
                ansy[repi] = y - (manh - i);
                flg[x + i][y - (manh - i)] = true;
                return;
            }
        }
        if (y + (manh - i) <= m)
        {
            if (flg[x + i][y + (manh - i)] == false)
            {
                ansx[repi] = x + i;
                ansy[repi] = y + (manh - i);
                flg[x + i][y + (manh - i)] = true;
                return;
            }
        }
    }
    manh++;
    return srch(x, y, n, m, repi, manh);
}