#include <iostream>
#include <stdio.h>

signed main()
{
    int n;
    std::cin >> n;
    int x = -2147483648;
    bool flag = false;
    for (int i = 0; i < n; ++i)
    {
        int y;
        std::cin >> y;
        if (y == x)
        {
            std::cout << "NO" << std::endl;
            return 0;
        }
        else if (y > x && !flag)
        {
            x = y;
        }
        else if (y < x && !flag)
        {
            flag = !flag;
            x = y;
        }
        else if (y < x && flag)
        {
            x = y;
        }
        else
        {
            std::cout << "NO" << std::endl;
            return 0;
        }
    }
    std::cout << "YES" << std::endl;
    return 0;
}