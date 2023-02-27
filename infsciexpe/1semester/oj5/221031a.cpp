#include <iostream>
#include <stdio.h>
using namespace std;

int a[200005];

signed main()
{
    int n, req, p = 0, x;
    int j = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        a[x] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &req);

        if (a[req] >= p)
        {
            printf("%d ", a[req] - p);
            p = a[req];
        }
        else
        {
            printf("0 ");
        }
    }
    return 0;
}