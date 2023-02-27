#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int main()
{
    unsigned long long mt, kt, pk = 0, ans = 0;
    unsigned long long m, k;
    bool flag = false;
    scanf("%llu%llu", &m, &k);
    if (k >= m)
        printf("0");
    else
    {
        mt = m;
        kt = k;
        while (kt > 0)
        {
            kt = kt >> 1;
            pk++; // pk代表k的位数
        }
        ans = (m >> pk);
        m = (m << (64 - pk)) >> (64 - pk);
        for (long long i = pk; i >= 1; i--)
        {
            mt = m;
            kt = k;
            mt = mt >> (i - 1);
            kt = kt >> (i - 1);
            ans = ans << 1;
            if (mt == 0 && kt == 1)
                flag = true;
            if (mt == 1 && kt == 0 && flag == false)
                ans++;
            m = m << (65 - i);
            k = k << (65 - i);
            m = m >> (65 - i);
            k = k >> (65 - i);
        }
        printf("%llu", ans);
    }
    return 0;
}