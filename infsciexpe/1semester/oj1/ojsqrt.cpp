#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    double n;
    double ans;
    double last;
    scanf("%lf", &n);
    if (n == 1.00)
    {
        printf("1");
        return 0;
    }
    double half = n / 2.0;
    ans = half;
    while (abs(ans - last) > 0.001)
    {
        last = ans;
        ans = (ans + n / ans) / 2;
    }
    printf("%.2lf", ans);
    return 0;
}