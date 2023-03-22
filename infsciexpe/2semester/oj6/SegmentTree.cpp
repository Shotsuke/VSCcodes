#include <iostream>
using namespace std;

int tree[2010], arr[1005], mark[2010];

void treebuild(int l, int r, int p)
{
    if (l == r)
    {
        tree[p] = arr[l];
    }
    else
    {
        int mid = (l + r) / 2;
        treebuild(l, mid, p * 2);
        treebuild(mid + 1, r, 2 * p + 1);

        tree[p] = tree[2 * p] + tree[2 * p + 1];
    }
    return;
}

inline void pushdown(int p, int len)
{
    mark[p * 2] += mark[p];
    mark[p * 2 + 1] += mark[p];
    tree[p * 2] += mark[p] * (len - len / 2);
    tree[p * 2 + 1] += mark[p] * len;
    mark[p] = 0;
}

void update(int l, int r, int delta, int p, int cl, int cr)
{
    if (l <= cl && cr <= r)
    {
        tree[p] += (cr - cl + 1) * delta;
        if (cr != cl)
        {
            mark[p] += delta;
        }
        return;
    }
    else if (cr < l || cl > r)
    {
        return;
    }
    else
    {
        int mid = (cl + cr) / 2;
        pushdown(p, cr - cl + 1);
        update(l, r, delta, p * 2, cl, mid);
        update(l, r, delta, p * 2 + 1, mid + 1, cr);
        tree[p] = tree[p * 2] + tree[p * 2 + 1];
        return;
    }
}

int req(int l, int r, int p, int cl, int cr)
{
    if (cr < l || cl > r)
    {
        return 0;
    }
    else if (l <= cl && cr <= r)
    {
        return tree[p];
    }
    else
    {
        int mid = (cr + cl) / 2;
        pushdown(p, cr - cl + 1);
        return req(l, r, p * 2, cl, mid) +
               req(l, r, p * 2 + 1, mid + 1, cr);
    }
}

signed main()
{
    int n, q;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    treebuild(1, n, 1);
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        int comm;
        cin >> comm;
        if (comm == 1)
        {
            int l, r;
            cin >> l >> r;
            cout << req(++l, r, 1, 1, n) << endl;
        }
        else
        {
            int ord, tovalue;
            cin >> ord >> tovalue;
            ord++;
            int delta = tovalue - arr[ord];
            arr[ord] = tovalue;
            update(ord, ord, delta, 1, 1, n);
        }
    }
    return 0;
}