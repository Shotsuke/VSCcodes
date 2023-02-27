#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int n;
    unsigned long long x = 1, y = 1;
    scanf("%d", &n);
    int j;
    int a[30] = {0};
    for (int i = 2 * n; i > n; i--)
    {
        x *= i;
        j = 1;
        for (; j <= n + 1; j++)
        {
            if (x % j == 0 && a[j] == 0)
            {
                a[j] = 1;
                x /= j;
            }
        }
    }
    printf("%lld", x);
    return 0;
}