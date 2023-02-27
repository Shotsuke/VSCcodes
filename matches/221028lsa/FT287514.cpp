#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string.h>
using namespace std;
signed main()
{
    int n;
    string s;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        for (int j = s.length() - 1; j >= 0; j--)
        {
            if (s[j] == '*')
                continue;
            cout << s[j];
        }
        cout << endl;
    }
    return 0;
}