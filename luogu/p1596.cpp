#include <iostream>
#include <stdio.h>
using namespace std;
int num = 0;
int a[110][110] = {0};
void search(int i, int j)
{
    if (a[i][j] == 1)
    {
        a[i][j] = 0;
        search(i - 1, j - 1);
        search(i - 1, j);
        search(i - 1, j + 1);
        search(i, j - 1);
        search(i, j + 1);
        search(i + 1, j - 1);
        search(i + 1, j);
        search(i + 1, j + 1);
    }
    else
        return;
}
int main()
{
    int n, m;
    char t;
    scanf("%d%d", &n, &m);
    scanf("%c", &t);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%c", &t);
            if (t == 'W')
                a[i][j] = 1;
            else
                a[i][j] = 0;
        }
        scanf("%c", &t);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == 1)
            {
                search(i, j);
                num++;
            }
        }
    }
    printf("%d", num);
    return 0;
}