#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    long int n, p, k;
    long int ans = 0;
    long int a[10000] = {0};
    long int b[10000] = {0};
    p = 0;
    scanf("%ld%ld", &n, &k);
    for (long int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            p++;
            a[p] = i;
            b[p] = n / i;
        }
    }
    for (long int i = 1; i <= p; i++)
    {
        b[p + i] = a[p - i + 1];
        a[p + i] = b[p - i + 1];
    }
    for (long int i = 1; i <= 2 * p; i++)
    {
        if (b[i] >= k)
            ans = a[i];
    }
    printf("%ld", ans);
    return 0;
}