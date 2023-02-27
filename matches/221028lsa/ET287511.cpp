#include <iostream>
#include <stdio.h>
using namespace std;
signed main()
{

    int n, a[5], b[5], c[6] = {0};
    int amtab = 0, amtbc = 0, amtca = 0;
    bool flag = false;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        amtab = 0;
        flag = false;
        c[5] = 0;
        for (int j = 1; j <= 4; j++)
        {
            c[j] = 1;
        }
        for (int j = 1; j <= 4; j++)
        {
            scanf("%d", &a[j]);
        }

        for (int j = 1; j <= 4; j++)
        {
            scanf("%d", &b[j]);

            for (int k = 1; k <= 4; k++)
            {
                if (a[k] > b[j])
                    amtab++;
                else if (a[k] < b[j])
                    amtab--;
            }
        }

        while (c[5] == 0)
        {
            amtbc = amtca = 0;
            for (int j = 1; j <= 4; j++)
            {
                for (int k = 1; k <= 4; k++)
                {
                    if (c[j] > a[k])
                    {
                        amtca++;
                    }
                    else if (c[j] < a[k])
                    {
                        amtca--;
                    }

                    if (b[k] > c[j])
                    {
                        amtbc++;
                    }
                    else if (b[k] < c[j])
                    {
                        amtbc--;
                    }
                }
            }

            if (amtab > 0 && amtbc > 0 && amtca > 0)
            {
                printf("yes\n");
                flag = true;
                break;
            }
            if (amtab < 0 && amtbc < 0 && amtca < 0)
            {
                printf("yes\n");
                flag = true;
                break;
            }

            c[1]++;
            for (int l = 1; l <= 4; l++)
            {
                if (c[l] == 11)
                {
                    c[l] -= 10;
                    c[l + 1]++;
                }
            }
        }
        if (flag == false)
            printf("no\n");
    }
    return 0;
}