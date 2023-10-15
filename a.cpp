#include <iostream>
#include <deque>
using namespace std;
int price[100005];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int l = 1, r = 1;
    int minday = 1, maxday = 1;
    int maxdiff = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> price[i];
    }
    if (n == 1)
    {
        cout << "0" << endl;
        return 0;
    }

    deque<int> maxdays;
    for (int i = 1; i <= n; ++i)
    {
        if (maxdays.empty())
        {
            maxdays.push_back(i);
        }
        else
        {
            if (price[i] <= price[maxdays.back()])
            {
                maxdays.push_back(i);
            }
            else
            {
                while (!maxdays.empty() && price[maxdays.back()] < price[i])
                {
                    maxdays.pop_back();
                }
                maxdays.push_back(i);
            }
        }
    }

    // for (int i : maxdays)
    // {
    //     cout << i << endl;
    // }

    while (!maxdays.empty())
    {
        l = r;
        r = maxdays.front();
        for (int i = l; i < r; ++i)
        {
            maxdiff = max(maxdiff, price[r] - price[i]);
        }
        maxdays.pop_front();
    }

    cout << maxdiff << endl;
    return 0;
}