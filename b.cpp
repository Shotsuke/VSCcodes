#include <iostream>
#include <string.h>
using namespace std;
int a[1005][1005];
int nowx, nowy, l = 0, r, celling = 0, bottom;
int n, m;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
void dire(int dir)
{
    nowx += dx[dir];
    nowy += dy[dir];
}
void ctrlzdire(int dir)
{
    nowx -= dx[dir];
    nowy -= dy[dir];
}
bool nextin(int direction)
{
    bool flag = true;
    dire(direction);
    if (nowx == l || nowx == r)
        flag = false;
    if (nowy == celling || nowy == bottom)
        flag = false;
    ctrlzdire(direction);
    return flag;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int num = 0;
    cin >> m >> n;
    nowx = n + 1, nowy = 1;
    int direction = 1;
    r = n + 1;
    bottom = m + 1;

    memset(a, 0, sizeof(a));
    while (num < n * m)
    {
        num++;
        if (!nextin(direction))
        {
            switch (direction)
            {
            case 1:
                celling++;
                break;
            case 2:
                l++;
                break;
            case 3:
                bottom--;
                break;
            case 0:
                r--;
                break;
            }
            direction = (direction + 1) % 4;
        }
        dire(direction);
        a[nowy][nowx] = num;
    }
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}