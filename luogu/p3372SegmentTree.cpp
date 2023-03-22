#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string.h>
using namespace std;
long long a[100005];
long long tree[300005];
long long mark[300005];

void treebuild(long long l, long long r, long long p)
{
    if (l == r)
    {
        tree[p] = a[l];
    }
    else
    {
        long long mid = (l + r) / 2;
        treebuild(l, mid, p * 2);
        treebuild(mid + 1, r, p * 2 + 1);
        tree[p] = tree[p * 2] + tree[p * 2 + 1];
    }
}

inline void pushdown(long long p, long long len)
{
    mark[p * 2] += mark[p];
    mark[p * 2 + 1] += mark[p];
    tree[p * 2] += mark[p] * (len - len / 2);
    tree[p * 2 + 1] += mark[p] * (len / 2);
    mark[p] = 0;
}

void update(long long l, long long r, long long k, long long p, long long curl, long long curr)
{
    if (curl > r || curr < l)
    {
        return;
    }
    else if (curl >= l && curr <= r)
    {
        tree[p] += (curr - curl + 1) * k;
        if (curr != curl)
        {
            mark[p] += k;
        }
        return;
    }
    else
    {
        long long mid = (curl + curr) / 2;
        pushdown(p, curr - curl + 1);
        update(l, r, k, p * 2, curl, mid);
        update(l, r, k, 2 * p + 1, mid + 1, curr);
        tree[p] = tree[p * 2] + tree[p * 2 + 1];
        return;
    }
}

long long req(long long l, long long r, long long p, long long curl, long long curr)
{
    if (curr < l || curl > r)
    {
        return 0;
    }
    else if (curr <= r && curl >= l)
    {
        return tree[p];
    }
    else
    {
        long long mid = (curr + curl) / 2;
        pushdown(p, curr - curl + 1);
        return req(l, r, 2 * p, curl, mid) + req(l, r, 2 * p + 1, mid + 1, curr);
    }
}

signed main()
{
    long long n, m;
    long long ordi, x, y, k;
    scanf("%lld%lld", &n, &m);
    for (long long i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }
    treebuild(1, n, 1);
    for (long long i = 1; i <= m; i++)
    {
        scanf("%lld", &ordi);
        if (ordi == 1)
        {
            scanf("%lld%lld%lld", &x, &y, &k);
            update(x, y, k, 1, 1, n);
        }
        else
        {
            scanf("%lld%lld", &x, &y);
            printf("%lld\n", req(x, y, 1, 1, n));
        }
    }
    return 0;
}