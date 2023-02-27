#include <iostream>
#include <stdio.h>
#include <cmath>
#include <stdlib.h>
#include <cstring>
#include <string.h>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int henoprime[1000000] = {0};
bool ans[10000005] = {false};
bool isprime(int x)
{
    if (x == 1)
        return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}
signed main()
{
    int henoptr = 0;
    int n, k, num = 0;
    scanf("%d%d", &k, &n);
    for (int i = 2; i <= k; i++)
    {
        if (!isprime(i))
        {
            continue;
        }
        henoptr++;
        henoprime[henoptr] = i;
    }
    for (int i = 1; i <= henoptr; i++)
    {
        for (int j = 2; j * henoprime[i] <= n; j++)
        {
            if (!ans[j * henoprime[i]])
            {
                ans[j * henoprime[i]] = true;
                num++;
            }
        }
    }
    printf("%d", n - num - 1);
    return 0;
}