#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

bool light[1005][1005] = {false};
signed main()
{
    int n, m, q, req, ans = 0;
    string s, onoff;
    cin >> n >> m >> q;
    for (int i = 0; i < q; ++i)
    {
        cin >> s >> req >> onoff;
        if (s == "row")
        {
            if (onoff == "on")
            {
                for (int j = 1; j <= m; ++j)
                {
                    light[req][j] = 1;
                }
            }
            else
            {
                for (int j = 1; j <= m; ++j)
                {
                    light[req][j] = 0;
                }
            }
        }
        else
        {
            if (onoff == "on")
            {
                for (int j = 1; j <= n; ++j)
                {
                    light[j][req] = 1;
                }
            }
            else
            {
                for (int j = 1; j <= n; ++j)
                {
                    light[j][req] = 0;
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            ans += light[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}