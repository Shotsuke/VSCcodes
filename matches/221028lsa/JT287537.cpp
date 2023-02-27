#include <iostream>
#include <stdio.h>
using namespace std;
signed main()
{
    long long n;
    while (cin >> n)
        printf("%lld\n", 1 + n * (n - 1) / 2 + n * (n - 1) * (n - 2) * (n - 3) / 24);
    return 0;
}