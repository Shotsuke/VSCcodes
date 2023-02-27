#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

long long juese[200005];
long double gailv[200005];
long double expe[1100000];

void dfs(int i, long long n, int amt, long long sum, int strt, int m);

int main()
{

    long long n, m, panduan = 0;
    scanf("%lld%lld", &n, &m);
    for (long long i = 1; i <= m; i++)
    {
        scanf("%lld", &juese[i]);
        scanf("%Lf", &gailv[i]);
        panduan = (panduan | juese[i]);
    }

    if (pow(2, n) - 1 - panduan != 0)
    {
        printf("-1");
        return 0;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        dfs(i, n, 0, 0, -1, m);
    }
    printf("%Lf", expe[0]);
    return 0;
}
void dfs(int i, long long n, int amt, long long sum, int strt, int m)
{ // dfs递归：枚举 ， i:需要选择1的个数 ， n：总个数
    // amt：已选1的个数 sum：目前所选之和 strt:已枚举之尾
    if (amt == i)
    {
        long double psbl, temp;
        psbl = 0.0;
        temp = 0.0;
        for (int j = 1; j <= m; j++)
        { // f[i]=(f[i]+1)*p0+累加(f[i|juese[枚举]]+1)*p枚举
            if ((sum | juese[j]) > sum)
                temp += (expe[(sum | juese[j])] + 1) * gailv[j];
            else
                psbl += gailv[j];
        }
        expe[sum] = (psbl + temp) / (1.0 - psbl);
        return;
    }

    for (int k = strt + 1; k <= n - (i - amt); k++)
    {
        long long sumtemp = 0;
        sumtemp = sum + (1 << k);
        dfs(i, n, amt + 1, sumtemp, k, m);
    }

    return;
}