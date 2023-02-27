#include <iostream>
#include <stdio.h>
using namespace std;
int n, k;
long long ans = 0;
int a[25] = {0};
int isprime(int x)
{
    if (x == 1)
        return 0;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return 0;
    }
    return 1;
}
void dfs(int amt, int sum, int sta)
{
    // amt=已选个数
    // sum=已选之和
    // sta=已枚举之尾
    // dfs递归=枚举下一个
    if (amt == k)
    {
        if (isprime(sum))
        {
            ans++; //全局给ans++
        }
        return; //无论是否为质数，均结束
    }
    for (int i = sta + 1; i <= n - (k - amt) + 1; i++)
    {
        dfs(amt + 1, sum + a[i], i);
        // i=sta+1联动i：枚举下一位的可能情况，并传递已枚举之尾
        // amt++；sum++
    }
    return;
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    dfs(0, 0, 0);
    printf("%d", ans);
    return 0;
}