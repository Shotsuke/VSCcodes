#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string.h>
using namespace std;
struct A
{
    string name;
    int year;
    int zone;
};

A game[10005];
signed main()
{
    int n = 0, len = 0;
    string s;
    int temp = 0;
    cin >> s;
    for (int k = 0; k <= s.length() - 1; k++)
    {
        n *= 10;
        n += s[k] - 48;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        game[i].name = s;
        scanf("%d%d", &game[i].year, &game[i].zone);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << game[i].name;
        printf(" %d %d\n", game[i].year, game[i].zone);
    }
    return 0;
}