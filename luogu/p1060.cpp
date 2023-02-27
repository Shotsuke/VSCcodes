#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int mon[30];
long long val[30];
long long dp[30][30005];
int main()
{
    int n, m; // n是钱钱，m是个数
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &mon[i], &val[i]);
        val[i] *= mon[i];
    }
    for (int i = mon[1]; i <= n; i++)
    {
        dp[1][i] = val[1];
    }
    for (int i = 1; i <= m; i++) //遍历物品
    {
        for (int j = 0; j <= n; j++) //遍历背包容量
        {
            if (j < mon[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - mon[i]] + val[i]);
        }
    }
    printf("%lld", dp[m][n]);
    return 0;
}