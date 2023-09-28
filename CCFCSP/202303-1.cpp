#include <iostream>
#include <stdio.h>
using namespace std;

bool inIt(int x, int y, int a, int b)
{
    return x <= a && x >= 0 && y >= 0 && y <= b;
}
signed main()
{
    int n, a, b;
    int posi[105][6] = {0};
    cin >> n >> a >> b;
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= 4; ++j)
        {
            cin >> posi[i][j];
        }
        if (inIt(posi[i][1], posi[i][2], a, b) && inIt(posi[i][3], posi[i][4], a, b))
        {
            ans += (posi[i][3] - posi[i][1]) *
                   (posi[i][4] - posi[i][2]);
        }
        else if (inIt(posi[i][1], posi[i][2], a, b) && !inIt(posi[i][3], posi[i][4], a, b))
        {
            ans += (min(a, posi[i][3]) - posi[i][1]) * (min(b, posi[i][4]) - posi[i][2]);
        }
        else if (!inIt(posi[i][1], posi[i][2], a, b) && inIt(posi[i][3], posi[i][4], a, b))
        {
            ans += (posi[i][3] - max(0, posi[i][1])) * (posi[i][4] - max(0, posi[i][2]));
        }
        else
        {
            long long temp = (min(posi[i][3], a) - max(posi[i][1], 0)) *
                             (min(posi[i][4], b) - max(posi[i][2], 0));
            if (min(posi[i][3], a) - max(posi[i][1], 0) > 0 &&
                min(posi[i][4], b) - max(posi[i][2], 0) > 0)
                ans += temp;
        }
    }
    cout << ans;
    return 0;
}