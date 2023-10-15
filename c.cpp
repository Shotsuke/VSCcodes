#include <iostream>
#include <string.h>
#include <vector>

using namespace std;
vector<string> a0;
vector<string> a1;
char bubble[100005];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    string low;
    cin >> n >> k;
    k = n - k;

    a0.resize(n + 1);
    a1.resize(n + 1);

    for (int i = 0; i < n; ++i)
    {
        cin >> bubble[i];
    }

    // init dp
    a0[0] = bubble[0];
    for (int i = 1; i < n; ++i)
    {
        a0[i] = min(a0[i - 1], low + bubble[i]);
    }

    for (int i = 1; i < k; ++i)
    {
        if (i & 1)
        {
            a1[i] = a0[i - 1] + bubble[i];
            for (int j = i + 1; j < n; ++j)
            {
                a1[j] = min(a1[j - 1], a0[j - 1] + bubble[j]);
            }
        }
        else
        {
            a0[i] = a1[i - 1] + bubble[i];
            for (int j = i + 1; j < n; ++j)
            {
                a0[j] = min(a0[j - 1], a1[j - 1] + bubble[j]);
            }
        }
    }
    if (n & 1)
        low = a1[n - 1];
    else
        low = a0[n - 1];
    while (!low.empty() && low[0] == '0')
    {
        low = low.substr(1);
    }
    if (!low.empty())
        cout << low << endl;
    else
        cout << 0 << endl;
    return 0;
}