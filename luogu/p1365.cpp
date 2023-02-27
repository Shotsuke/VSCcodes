#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string.h>
using namespace std;
int main()
{
    string s;
    int n;
    long double contin = 0;
    long double ans = 0.0;
    scanf("%d", &n);
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'o')
        {
            ans += 2 * contin + 1;
            contin++;
        }
        else if (s[i] == 'x')
        {
            contin = 0;
        }
        else
        {
            ans += contin + 0.5;
            contin = 0.5 * contin + 0.5;
        }
    }
    printf("%.4Lf", ans);
    return 0;
}