#include <iostream>
#include <stdio.h>
using namespace std;
int r[500][500];
int s[500][500];
int super[500][500];
int main()
{
    int n;
    char a;
    scanf("%d", &n);
    scanf("%c", &a);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%c", &a);
            if (a == '1')
                r[i][j] = 1;
        }
    }
    scanf("%c", &a);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%c", &a);
            if (a == '1')
                s[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (r[j][i] + super[j][i])
            {
                for (int k = 1; k <= n; k++)
                {
                    if (s[i][k] + super[i][k])
                        super[j][k] = 1;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d", super[i][j]);
        }
    }
    return 0;
}