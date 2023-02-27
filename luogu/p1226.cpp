#include <iostream>
#include <stdio.h>
using namespace std;
long long binpow(long long a, long long b, long long p)
{
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2, p);
    if (b % 2)
        return ((res * res) % p) * a % p;
    else
        return res * res % p;
}
/*long long binpow(long long a, long long b, long long p)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}*/
int main()
{
    long long a, b, p;
    scanf("%lld %lld %lld", &a, &b, &p);
    printf("%lld^%lld mod %lld=%lld", a, b, p, binpow(a % p, b, p));
}