#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string.h>
using namespace std;
int a[100005], now[100005];
signed main()
{
    int n, ima = 1, nop = 0, last = 1, max = 0;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i + 1] + a[i] == 1)
        {
            ima++;
        }
        else
        {
            nop++;
            now[nop] = ima;
            ima = 1;
        }
    }
    nop++;
    now[nop] = ima;
    if (nop <= 3)
    {
        for (int i = 1; i <= nop; i++)
        {
            max += now[i];
        }
    }
    else
    {
        max = now[1] + now[2] + now[3];
        for (int i = 4; i <= nop; i++)
        {
            if (now[i] + now[i - 1] + now[i - 2] > max)
                max = now[i] + now[i - 1] + now[i - 2];
        }
    }
    printf("%d", max);
    return 0;
}