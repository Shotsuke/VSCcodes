#include <iostream>
#include <string.h>
using namespace std;
int allocation[21][21];
signed main()
{
    memset(allocation, 0, sizeof(allocation));
    allocation[1][1] = 100;
    allocation[2][1] = 100;
    allocation[2][2] = -1;
    int n, k = 3;
    cin >> n;
    while (k <= n)
    {
        int support = 1, minn = -1, tot = 100;
        while (support <= k / 2)
        {
            for (int i = k - 1; i >= 1; --i)
            {
                if (allocation[k - 1][i] == minn)
                {
                    allocation[k][i] = minn + 1;
                    tot -= allocation[k][i];
                    support++;
                    if (support > k / 2)
                        break;
                }
            }
            minn++;
        }
        allocation[k][k] = tot;
        k++;
    }
    for (int i = n; i >= 1; --i)
    {
        cout << allocation[n][i] << " ";
    }
    return 0;
}