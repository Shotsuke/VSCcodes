#include <iostream>
#include <stdio.h>

signed main()
{
    int n, ans = 0;
    std::cin >> n;
    if (n < 3)
    {
        std::cout << ans << std::endl;
        return 0;
    }
    int pre, now, beh, situ = 0;
    std::cin >> pre >> now;
    if (now > pre)
        situ = 1;
    else if (now < pre)
        situ = 2;
    for (int i = 0; i < n - 2; ++i)
    {
        std::cin >> beh;
        if ((situ == 1 || situ == 0) && beh < now)
        {
            ++ans;
            situ = 2;
        }
        else if ((situ == 2 || situ == 0) && beh > now)
        {
            ++ans;
            situ = 1;
        }
        pre = now;
        now = beh;
    }
    std::cout << ans << std::endl;
    return 0;
}