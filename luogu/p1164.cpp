#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int n, m;
int dp[105][10005];
int main()
{
    int price[105];
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &price[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (j < price[i])
                dp[i][j] = dp[i - 1][j];
            else if (j == price[i])
                dp[i][j] = dp[i - 1][j] + 1;
            else
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - price[i]];
        }
    }
    printf("%d", dp[n][m]);
    return 0;
}