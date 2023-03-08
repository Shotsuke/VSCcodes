#include <iostream>
#include <string.h>
/*
    Len[s][k] = Len[s-1][k] + Len[s-1][k-1] + 1
    s/k 1   2   3   4
    1   1   1   1   1
    2   2   3   3   3
    3   3   6   7   7
    4   4   10  14  15
    5   5   15  25  30
    6   6   21  41  56
*/
signed main()
{
    long long n_requeres, k_eggs, s_times, n_floor;
    long long Len[50][6];
    memset(Len, 0, sizeof(Len));
    std::cin >> n_requeres;

    for (int i = 1; i < 50; ++i)
    {
        for (int j = 1; j < 6; ++j)
        {
            Len[i][j] = Len[i - 1][j] + Len[i - 1][j - 1] + 1;
        }
    }
    for (int i = 0; i < n_requeres; ++i)
    {
        long long ans = 1;
        std::cin >> k_eggs >> n_floor;
        while (Len[ans][k_eggs] < n_floor)
        {
            ans++;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}