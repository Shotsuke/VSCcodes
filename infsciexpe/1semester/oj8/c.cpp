#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
using namespace std;
string s[100005], t;
signed main()
{
    int n, m, diff;
    bool flag;

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }

    for (int i = 1; i <= m; i++)
    {
        cin >> t;
        flag = false;
        int lth = t.length();
        for (int j = 1; j <= n; j++)
        {
            if (s[j].length() != lth)
                continue;
            diff = 0;
            for (int k = 0; k < lth; k++)
            {
                if (s[j][k] != t[k])
                    diff++;
                if (diff == 2)
                    break;
            }
            if (diff == 1)
            {
                printf("YES\n");
                flag = true;
                break;
            }
        }
        if (!flag)
            printf("NO\n");
    }
    return 0;
}