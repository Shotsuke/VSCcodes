#include <bits/stdc++.h>
using namespace std;
long long board[30][30] = {0}, xn, ym, xh, yh;
bool c[30][30] = {false};
int main()
{
    scanf("%lld%lld%lld%lld", &xn, &ym, &xh, &yh);
    xn += 2;
    ym += 2;
    xh += 2;
    yh += 2;
    c[xh][yh] = true;
    c[xh + 2][yh + 1] = true;
    c[xh + 2][yh - 1] = true;
    c[xh - 2][yh + 1] = true;
    c[xh - 2][yh - 1] = true;
    c[xh + 1][yh + 2] = true;
    c[xh + 1][yh - 2] = true;
    c[xh - 1][yh + 2] = true;
    c[xh - 1][yh - 2] = true;
    board[1][2] = 1;
    for (int i = 2; i <= xn; i++)
    {
        for (int j = 2; j <= ym; j++)
        {
            if (c[i][j] == false)
            {
                board[i][j] = board[i - 1][j] + board[i][j - 1];
            }
        }
    }
    printf("%lld", board[xn][ym]);
    return 0;
}
