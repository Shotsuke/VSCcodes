#include <bits/stdc++.h>
using namespace std;
long long ans = 0;
long long remember[30][30][30] = {0};
long long w(long long a, long long b, long long c);
int main()
{
    long long a, b, c;
    while (scanf("%lld%lld%lld", &a, &b, &c))
    {
        if (a == -1 && b == -1 && c == -1)
            break;
        printf("w(%lld, %lld, %lld) = ", a, b, c);
        if (a > 20)
            a = 21;
        if (b > 20)
            b = 21;
        if (c > 20)
            c = 21;
        ans = w(a, b, c);
        printf("%lld\n", ans);
    }
    return 0;
}
long long w(long long a, long long b, long long c)
{

    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    else if (a > 20 || b > 20 || c > 20)
        return w(20, 20, 20);
    else if (remember[a][b][c] != 0)
        return remember[a][b][c];
    else if (a < b && b < c)
    {
        remember[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
        return remember[a][b][c];
    }
    else
    {
        remember[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
        return remember[a][b][c];
    }
}