#include <iostream>
#include <stdio.h>
#include <map>
#include <algorithm>
#define N 200005
using namespace std;
// Kakaa!!
long long a[N], b[N], index[N];
signed main()
{
    long long n, suma = 0, sumb = 0;
    scanf("%lld", &n);

    for (long long i = 1; i <= n; i++)
    {
        scanf("%lld%lld", &a[i], &b[i]);
        index[i] = i;
        suma += a[i];
        sumb += b[i];
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);

    printf("%lld", max(b[1] + suma, a[1] + sumb));

    return 0;
}