#include <iostream>
#include <math.h>
using namespace std;

bool isprime(long long x)
{
    for (long long i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

signed main()
{
    long long a = 5;
    bool flag;
    for (long long k = 2; k <= 500; ++k)
    {
        long long i = 7 * k;
        flag = false;
        if (i % a == 0)
        {
            cout << i << "\tNOT" << endl;
            continue;
        }
        for (long long j = 1; j <= (i + 1) / 2; ++j)
        {
            if (j * j % i == a % i)
            {
                flag = true;
                cout << i << "\tQR: " << j << endl;
                break;
            }
        }
        if (!flag)
        {
            cout << i << "\tQNR" << endl;
        }
    }
    return 0;
}
