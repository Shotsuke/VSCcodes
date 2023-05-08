#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#define MOD 998244353
using namespace std;
vector<deque<long long>> articles;
signed main()
{
    int n, m;
    cin >> n >> m;
    articles.resize(2 * m + 3);
    for (int i = 1; i <= 2 * m + 1; ++i)
    {
        articles[i].push_back(1);
    }
    // for (int i = m + 2; i <= 2 * m + 1; ++i)
    // {
    //     articles[i].push_back(0);
    // }
    for (int i = 2; i <= n; ++i)
    {
        long long sumforposi = 0, sumfornega = 0;
        for (int j = 1; j <= m; ++j)
        {
            sumforposi += articles[j].front();
            articles[j].pop_front();
            sumforposi %= MOD;
            articles[2 * m + 2 - j].push_back(sumforposi);
        }                                      // 处理了负数
        sumforposi += articles[m + 1].front(); // 补上之前的0
        articles[m + 1].pop_front();
        sumforposi %= MOD;
        for (int j = 1; j <= m; ++j)
        {
            articles[j].push_back(sumforposi + sumfornega);
            sumfornega += articles[m + 1 + j].front();
            articles[m + 1 + j].pop_front();
            sumfornega %= MOD;
        }
        articles[m + 1].push_back(sumfornega + sumforposi);
    }
    long long ans = 0;
    for (int i = 1; i <= 2 * m + 1; ++i)
    {
        ans += articles[i].front();
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}