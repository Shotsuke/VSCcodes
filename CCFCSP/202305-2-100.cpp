#include <iostream>
using namespace std;
long long Q[10005][25], K[10005][25], V[10005][25], W[10005], tmp[10005][25], ans[10005][25];
signed main()
{
    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= d; ++j)
        {
            cin >> Q[i][j];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= d; ++j)
        {
            cin >> K[i][j];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= d; ++j)
        {
            cin >> V[i][j];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> W[i];
    }
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                tmp[i][j] += K[k][i] * V[k][j];
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            for (int k = 1; k <= d; k++)
                ans[i][j] += Q[i][k] * tmp[k][j];
            ans[i][j] *= W[i];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= d; j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}