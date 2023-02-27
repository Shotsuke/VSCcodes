#include <iostream>
#include <stdio.h>
using namespace std;
bool isprime(long long x)
{
    for (long long j = 2; j * j <= x; j++)
    {
        if (x % j == 0)
        {
            return false;
        }
    }
    return true;
}
signed main()
{
    long long n, p = 1;
    scanf("%lld", &n);
    while (n > 1)
    {
        p++;
        if (isprime(p))
        {
            while (n % p == 0)
            {
                n /= p;
                printf("%lld * ", p);
            }
        }
        else
            continue;
    }
    printf("finished");
    return 0;
}
