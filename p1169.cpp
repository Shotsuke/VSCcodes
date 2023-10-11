#include <iostream>
using namespace std;
class node
{
public:
    int maxinrow, maxincol, val;
    int validrow, validcol;
} a[2001][2001];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j].val;
        }
    }
    a[1][1].maxincol = a[1][1].maxinrow = a[1][1].validcol = a[1][1].validrow = 1;
    for (int i = 2; i <= n; ++i)
    {
        a[i][1].validcol = a[i][1].maxincol = 1;
        if (a[i][1].val != a[i - 1][1].val)
        {
            a[i][1].maxinrow = a[i - 1][1].maxinrow + 1;
            a[i][1].validrow = a[i - 1][1].maxinrow + 1;
        }
        else
        {
            a[i][1].maxinrow = a[i][1].validrow = 1;
        }
    }
    for (int i = 2; i <= m; ++i)
    {
        a[1][i].maxinrow = a[1][i].validrow = 1;
        if (a[1][i].val != a[1][i - 1].val)
        {
            a[1][i].validcol = a[1][i - 1].maxincol + 1;
            a[1][i].maxincol = a[1][i - 1].maxincol + 1;
        }
        else
        {
            a[1][i].validcol = a[1][i].maxincol = 1;
        }
    }
    int ans1 = 1, ans2 = 1;
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 2; j <= m; ++j)
        {
            if (a[i][j].val != a[i - 1][j].val)
            {
                a[i][j].maxinrow = a[i - 1][j].maxincol + 1;
            }
            else
            {
                a[i][j].maxinrow = 1;
            }

            if (a[i][j].val != a[i][j - 1].val)
            {
                a[i][j].maxincol = a[i][j - 1].maxincol + 1;
            }
            else
            {
                a[i][j].maxincol = 1;
            }

            if (a[i][j].val == a[i - 1][j - 1].val &&
                a[i][j].val != a[i - 1][j].val &&
                a[i][j].val != a[i][j - 1].val)
            {
                a[i][j].validcol = min(a[i - 1][j - 1].validcol, a[i][j - 1].maxincol) + 1;
                a[i][j].validrow = min(a[i - 1][j - 1].validrow, a[i - 1][j].maxinrow) + 1;
            }
            else
            {
                a[i][j].validcol = a[i][j].validrow = 1;
            }
            if (a[i][j].validcol == a[i][j].validrow)
            {
                ans1 = max(ans1, a[i][j].validcol * a[i][j].validrow);
            }
            ans2 = max(ans2, a[i][j].validcol * a[i][j].validrow);
        }
    }
    cout << ans1 << endl;
    return 0;
}