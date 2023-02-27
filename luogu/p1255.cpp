#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int a[6000] = {0}, b[6000] = {0}, c[6000] = {0};
    int x, p = 0;
    scanf("%d", &x);
    a[0] = 1;
    b[0] = 2;
    if (x == 0)
        printf("0");
    else if (x == 1)
        printf("1");
    else if (x == 2)
        printf("2");
    else
    {
        for (int i = 3; i <= x; i++)
        {
            int j = 0;
            for (; j <= p; j++)
            {
                c[j] = a[j] + b[j];
                if (c[j] >= 10 && j < p)
                {
                    c[j] -= 10;
                    a[j + 1]++;
                }
                if (c[j] >= 10 && j == p)
                {
                    c[j] -= 10;
                    c[j + 1]++;
                }
            }
            if (c[j])
                p++;
            for (int l = 0; l <= p; l++)
            {
                a[l] = b[l];
                b[l] = c[l];
            }
        }
        for (; p >= 0; p--)
            printf("%d", c[p]);
    }
    return 0;
}