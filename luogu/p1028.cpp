#include <iostream>
#include <stdio.h>
using namespace std;
long long ans = 0;
/*int f_remember[1005];
int f(int n){
    if(n == 1) return 1;
    if(f_remember[n]) return f_remember[n];
    int result = 0;
    for(int i = 1; i <= n/2; ++i)
        result += f(i);
    return f_remember[n] = result + 1;  //记忆
}*/
//记忆剪枝代码O(n^2)+O(n)
long long geshu(int x);
int main()
{
    int n;
    scanf("%d", &n);
    ans = geshu(n);
    printf("%lld", ans);
    return 0;
}
long long geshu(int x)
{
    long long temp = 0;
    if (x == 1)
        return 1;
    for (int i = x / 2; i >= 1; i--)
    {
        if (i % 2 == 1 && i >= 3)
        {
            temp += 2 * geshu(i - 1);
            i--;
        }
        else
            temp += geshu(i);
    }
    return temp + 1;
}