#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

bool hasY(string x, char y)
{
    if (x.find(y) < 0 || x.find(y) >= x.length())
        return false;
    else
        return true;
}

signed main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        int n;
        cin >> n;
        string t;
        cin >> t;
        string ans0, ans1;
        int l = t.length();
        for (int j = 0; j < n; ++j)
        {
            ans0 += '0';
            ans1 += '1';
        }
        if (!hasY(t, '0'))
        {
            cout << ans0 << endl;
            continue;
        }
        if (!hasY(t, '1'))
        {
            cout << ans1 << endl;
            continue;
        }
        if (l & 1)
        {
            if (t[(l - 1) / 2] == '0')
            {
                cout << ans1 << endl;
                continue;
            }
            else
            {
                cout << ans0 << endl;
                continue;
            }
        }
        else
        {
            if (t[l / 2] == '1')
            {
                cout << ans0 << endl;
                continue;
            }
            else
            {
                cout << ans1 << endl;
                continue;
            }
        }
    }
    return 0;
}