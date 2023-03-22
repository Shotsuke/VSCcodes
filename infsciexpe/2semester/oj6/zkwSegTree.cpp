#include <iostream>
#include <math.h>
using namespace std;
long long arr[1030], tree[2050], N;
long long lcm(long long x, long long y)
{ // Get a lcm number.
    long long temp = x * y;
    if (x == 0 && y == 0)
        return 1;
    while (x > 0 && y > 0)
    {
        if (x >= y)
            x %= y;
        else
            y %= x;
    }
    return temp / (x + y);
}
void buildtree(long long arr[], long long n)
{ // Build a tree with the wize of 2 * N - 1.
    N = 1 << (long long)log2(double(n + 2));
    for (long long i = 0; i < n; ++i)
    {
        tree[i + N] = arr[i];
    }
    for (long long i = N - 1; i >= 1; --i)
    {
        tree[i] = lcm(tree[i << 1], tree[i << 1 | 1]);
    }
}
long long req(long long l, long long r)
{
    long long ans = 1;
    for (l += N - 1, r += N + 1; l ^ r ^ 1; l >>= 1, r >>= 1)
    {
        if (~l & 1)
            ans = lcm(ans, tree[l ^ 1]);
        if (r & 1)
            ans = lcm(ans, tree[r ^ 1]);
    }
    return ans;
}
signed main()
{
    long long n, q;
    cin >> n;
    for (long long i = 0; i < n; ++i)
        cin >> arr[i];
    buildtree(arr, n);

    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        int l, r;
        cin >> l >> r;
        cout << req(l, --r) << endl;
    }
    return 0;
}