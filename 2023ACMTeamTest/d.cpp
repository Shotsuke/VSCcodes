#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
set<long long> people;
map<long long, int> order;
map<long long, int> tendencyToOrder;
map<int, long long> orderToTendency;
signed main()
{
    int n, head = 1;
    long long x;
    cin >> n;
    int tail = n;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &x);
        people.insert(x);
        order[x] = i;
    }
    int abccc = 0;
    for (auto iter : people)
    {
        abccc++;
        tendencyToOrder[iter] = abccc;
        orderToTendency[abccc] = iter;
    }
    long double ave = (orderToTendency[head] + orderToTendency[tail]) * 1.0 / 2;
    for (int i = 1; i < n; ++i)
    {
        long long lowerbd = *people.upper_bound(ave);
        if ((tail - tendencyToOrder[lowerbd] + 1) * 2 > tail - head + 1)
        {
            people.erase(*people.begin());

            head++;
            ave = (*people.begin() + *people.rbegin()) * 1.0 / 2;
        }
        else
        {
            people.erase(*people.rbegin());

            tail--;
            ave = (*people.begin() + *people.rbegin()) * 1.0 / 2;
        }
    }
    cout << order[orderToTendency[head]] << endl;
    return 0;
}