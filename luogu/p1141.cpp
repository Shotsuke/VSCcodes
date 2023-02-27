#include <iostream>
#include <stdio.h>
using namespace std;
int a[1005][1005];
int ans[1000005];
int flag[1005][1005];
int x;
int y;
char s[1005];
void dfs(int i, int j, int z, int n, int rec)
{
    if (i < 1 || j < 1 || i > n || j > n || a[i][j] != z || flag[i][j])
        return;
    flag[i][j] = rec;
    ans[rec]++;
    dfs(i, j - 1, 1 - z, n, rec);
    dfs(i - 1, j, 1 - z, n, rec);
    dfs(i, j + 1, 1 - z, n, rec);
    dfs(i + 1, j, 1 - z, n, rec);
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s + 1);
        for (int j = 1; j <= n; j++)
            if (s[j] == '1')
                a[i][j] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &x, &y);
        if (flag[x][y] == 0)
        {
            dfs(x, y, a[x][y], n, i);
        }
        else
        {
            ans[i] = ans[flag[x][y]];
        }
    }
    for (int i = 1; i <= m; i++)
        printf("%d\n", ans[i]);
    return 0;
}