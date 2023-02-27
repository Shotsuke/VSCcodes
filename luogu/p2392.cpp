#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main()
{
    int s[10] = {0}, arr[10][25] = {0}, dp[1300] = {0}, ans = 0;
    int all;
    for (int i = 1; i <= 4; i++)
    {
        scanf("%d", &s[i]);
    }
    for (int i = 1; i <= 4; i++)
    {
        all = 0;
        for (int j = 1; j <= s[i]; j++)
        {
            scanf("%d", &arr[i][j]);
            all += arr[i][j];
        }                                              //读入
        for (int k = 1; k <= s[i]; k++)                //枚举物品k
            for (int j = all / 2; j >= arr[i][k]; j--) //枚举总时长j并递推
            {                                          // dp递推数组下标表示在不超过该时长时最多能够达到的时长
                dp[j] = max(dp[j], dp[j - arr[i][k]] + arr[i][k]);
            }
        ans += all - dp[all / 2];
        for (int l = 1; l <= all / 2; l++)
            dp[l] = 0;
    }
    printf("%d", ans);
    return 0;
}
