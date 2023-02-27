#include <iostream>
#include <stdio.h>
using namespace std;
signed main()
{
    int n, k = 1, amt = 0, kmin = 0, amtmin = 1e6;
    int pre[5005] = {0};
    bool stu[5005] = {false}, flag;
    char s;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        if (s == 'B')
            stu[i] = true;
        else
            stu[i] = false;
    }
    while (k <= n)
    {
        for (int i = 1; i <= n; i++)
            pre[i] = 0;
        amt = 0;
        flag = true;
        for (int i = 1; i <= n - k + 1; i++)
        {
            pre[i] ^= pre[i - 1];
            if (stu[i] ^ pre[i] == 1)
            {
                amt++;
                pre[i] ^= 1;
                pre[i + k] ^= 1;
            }
        }
        for (int i = n - k + 2; i <= n; i++)
        {
            pre[i] ^= pre[i - 1];
            if (stu[i] ^ pre[i] == 1)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            if (amt < amtmin)
            {
                kmin = k;
                amtmin = amt;
            }
        }
        k++;
    }
    if (k == 0)
        printf("0 0");
    else
        printf("%d %d", kmin, amtmin);
    return 0;
}