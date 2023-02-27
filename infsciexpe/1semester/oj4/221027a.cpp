#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int a[105][105];
int main()
{
    int n, x = 0, y = 0;
    int amt = 1;
    scanf("%d", &n);
    if (n % 2)
    {
        y = 1;
        x = (n + 1) / 2;
        a[y][x] = 1;
        while (amt <= n * n)
        {
            amt++;
            x++;
            y--;
            if ((x == n + 1 && y == 0) || a[y][x] != 0)
            {
                x--;
                y += 2;
            }
            else if (x > n && y >= 1 && y <= n)
                x = 1;
            else if (y < 1 && x >= 1 && x <= n)
                y = n;
            a[y][x] = amt;
        }
    }
    else
    {
        amt = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                amt++;
                a[i][j] = amt;
            }
        }
        for (int i = 1; i <= n / 2; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if ((i + j) % 2 == 1 && j <= n / 2)
                {
                    swap(a[i][j], a[n + 1 - i][n + 1 - j]);
                }
                if ((i + j) % 2 == 0 && j > n / 2)
                {
                    swap(a[i][j], a[n + 1 - i][n + 1 - j]);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
