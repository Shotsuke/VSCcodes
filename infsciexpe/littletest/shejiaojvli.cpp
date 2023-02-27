#include <iostream>
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <cstring>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
    int n, l = 0, r = 0, max = 0, ans[105] = {0}, amot = 0;
    int a[105];
    bool flag = false;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] == 1)
            flag = true;
    }
    if (flag == false)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", i);
        }
        return 0;
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (a[i] == 1)
        {
            if (a[i - 1] == 0)
                a[i - 1] = 2;
            if (a[i + 1] == 0)
                a[i + 1] = 2;
        }
    }
    if (a[0] == 1)
    {
        if (a[1] == 0)
            a[1] = 2;
    }
    if (a[n - 1] == 1)
    {
        if (a[n - 2] == 0)
            a[n - 2] = 2;
    }
    while (1)
    {
        while ((a[l] == 1 || a[l] == 2) && l < n)
            l++;
        if (l == n)
            break;
        r = l;
        while (a[r + 1] == 0 && r < n - 1)
            r++;
        if (l == 0)
        {
            max = r + 1;
            amot++;
            ans[amot] = 0;
        }
        else if (r == n - 1)
        {
            if (r - l + 1 > max)
            {
                max = r - l + 1;
                amot = 1;
                ans[1] = r;
            }
            else if (r - l + 1 == max)
            {
                amot++;
                ans[amot] = r;
            }
        }
        else
        {
            if ((r - l) / 2 + 1 > max)
            {
                max = (r - l) / 2 + 1;
                amot = 0;
                if ((r - l + 1) % 2)
                {
                    amot++;
                    ans[amot] = l + max - 1;
                }
                else
                {
                    amot++;
                    ans[amot] = l - 1 + max;
                    amot++;
                    ans[amot] = l + max;
                }
            }
            else if ((r - l) / 2 + 1 == max)
            {
                if ((r - l + 1) % 2)
                {
                    amot++;
                    ans[amot] = l + max - 1;
                }
                else
                {
                    amot++;
                    ans[amot] = l - 1 + max;
                    amot++;
                    ans[amot] = l + max;
                }
            }
        }
        l = r + 1;
    }
    if (amot == 0)
        printf("-1");
    for (int i = 1; i <= amot; i++)
        printf("%d ", ans[i]);
}