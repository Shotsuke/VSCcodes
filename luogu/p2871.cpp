#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int weight[4000], value[4000];
long long dp[30000];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m); // n个数，m背包大小
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &weight[i], &value[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= weight[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    printf("%lld", dp[m]);
    return 0;
}