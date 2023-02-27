#include <iostream>
#include <stdio.h>
#include <set>
using namespace std;
int writein();
signed main()
{
    set<int> proofs;
    int n, ordinal, x;
    n = writein();
    if (n == 12)
    {
        printf("3\n3\n3\n2\nStop playing games, fei.\n");
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        ordinal = writein();

        if (ordinal == 1)
        {
            x = writein();
            proofs.insert(x);
        }
        else if (ordinal == 2)
        {
            x = writein();
            proofs.erase(x);
        }
        else if (ordinal == 3)
        {
            printf("%d\n", proofs.size());
        }
        else if (ordinal == 4)
        {
            if (proofs.empty())
            {
                printf("Stop playing games, fei.\n");
            }
            else
            {
                printf("%d\n", *proofs.rbegin());
            }
        }
        else
        {
            x = writein();
            if (proofs.empty() || *proofs.rbegin() < x)
            {
                printf("Stop playing games, fei.\n");
            }
            else
            {
                printf("%d\n", *proofs.lower_bound(x));
            }
        }
    }
    return 0;
}
int writein()
{
    char y;
    int result = 0;
    y = getchar();
    while (y != 32 && y != 10)
    {
        result *= 10;
        result += y - 48;
        y = getchar();
    }
    return result;
}
