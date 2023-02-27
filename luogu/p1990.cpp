#include <iostream>
#include <stdio.h>
using namespace std;
int f[1000005] = {0}, g[1000005] = {0};
int main()
{
    int n;
    scanf("%d", &n);
    f[1] = 1;
    f[2] = 2;
    g[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        f[i] = (f[i - 1] + f[i - 2] + 2 * g[i - 1]) % 10000;
        g[i] = (g[i - 1] + f[i - 2]) % 10000;
    }
    printf("%d", f[n]);
    return 0;
}