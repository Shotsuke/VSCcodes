#include <iostream>
#include <vector>
#include <deque>
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    deque<int> up, down;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        if (up.empty())
        {
            up.push_back(i);
        }
        else
        {
            if (a[i] >= a[up.back()])
            {
                up.push_back(i);
            }
            else
            {
                while (!up.empty() && a[up.back()] > a[i])
                {
                    up.pop_back();
                }
                up.push_back(i);
            }
        }

        if (down.empty())
        {
            down.push_back(i);
        }
        else
        {
            if (a[i] <= a[down.back()])
            {
                down.push_back(i);
            }
            else
            {
                while (!down.empty() && a[down.back()] > a[i])
                {
                    down.pop_back();
                }
                down.push_back(i);
            }
        }
    }

    while ((!down.empty()) && (!up.empty()))
    {
        }

    return 0;
}