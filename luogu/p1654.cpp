#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string.h>
using namespace std;
int main()
{
    int n;
    double x;
    long double ans = 0.0, cur3 = 0.0, cur2 = 0.0, cur1 = 0.0, contin = 0.0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lf", &x);
        ans += x * (3 * cur2 + 3 * cur1 + 1);
        cur2 = x * (cur2 + 2 * cur1 + 1);
        cur1 = x * (cur1 + 1);
    }
    printf("%.1Lf", ans);
    return 0;
}