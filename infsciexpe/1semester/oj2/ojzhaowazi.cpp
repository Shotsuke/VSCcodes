#include <iostream>
#include <stdio.h>
using namespace std;
long int n, x;
long int ans;
long int a[10000];
long int b[10000];
int main()
{
    scanf("%ld", &n);
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        scanf("%ld", &x);
        ans = ans ^ x;
    }
    printf("%ld", ans);
    return 0;
}