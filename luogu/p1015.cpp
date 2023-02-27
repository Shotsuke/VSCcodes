#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string.h>
using namespace std;
bool huiwen(int x[], int l)
{
    for (int i = 0; i < l / 2; i++)
    {
        if (x[i] != x[l - 1 - i])
            return false;
    }
    return true;
}
int main()
{

    int n, ans = 0, len;
    scanf("%d", &n);
    int m[300] = {0};
    string s;
    cin >> s;
    if (n <= 10)
    {
        for (int i = 0; i < s.length(); i++)
        {
            m[i] = (int)s[i] - 48;
        }
    }
    else
    {
        for (int i = 0; i < s.length(); i++)
        {
            if ((int)s[i] - 48 >= 0 && (int)s[i] - 48 <= 9)
                m[i] = (int)s[i] - 48;
            else
                m[i] = (int)s[i] - 65 + 10;
        }
    }
    len = s.length();
    while (huiwen(m, len) == false && ans <= 30)
    {
        ans++;
        for (int i = 0; i < (len + 1) / 2; i++)
        {
            m[i] += m[len - 1 - i];
            m[len - 1 - i] = m[i];
        }
        for (int i = 0; i < len; i++)
        {
            if (m[i] >= n)
            {
                m[i] -= n;
                m[i + 1]++;
            }
        }
        if (m[len])
            len++;
        /*for (int i = 0; i < len; i++)
            printf("%d", m[i] >= 10 ? (char)(m[i] + 87) : m[i]);
        printf("\n");*/
    }
    if (ans <= 30)
        printf("STEP=%d", ans);
    else
        printf("Impossible!");
    return 0;
}