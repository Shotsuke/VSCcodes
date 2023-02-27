#include <iostream>
#include <stdio.h>

signed main()
{
    int n;
    std::cin >> n;
    int x = -2147483648;
    for (int i = 0; i < n; ++i)
    {
        int y;
        std::cin >> y;
        if (y > x)
            x = y;
        else
        {
            std::printf("NO\n");
            return 0;
        }
    }
    std::printf("YES\n");
    return 0;
}