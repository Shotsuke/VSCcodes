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
signed main()
{
    int a[10005] = {0};
    int num[10005] = {0};
    int n, k, all = 0, ansmin = 1e9, temp = 0, pre = 0, now = 0;
    bool flag = false;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &num[i]);
    }

    while (!a[n + 1])
    {
        a[1]++;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 2)
            {
                a[i + 1]++;
                a[i] = 0;
                continue;
            }
            break;
        }
        flag = true;
        temp = 0;

        for (int i = 1; i <= n - k + 1; i++)
        {
            all = 0;
            for (int j = i; j <= i + k - 1; j++)
            {
                all += a[j];
            }
            if (all < 2)
            {
                flag = false;
                break;
            }
        }

        if (flag)
            for (int i = 1; i <= n; i++)
            {
                if (a[i])
                {
                    temp += num[i];
                }
            }

        if (flag)
        {
            ansmin = min(ansmin, temp);
        }
    }

    printf("%d", ansmin);
    return 0;
}