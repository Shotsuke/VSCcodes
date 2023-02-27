#include <iostream>
#include <stdio.h>
#include <cmath>
#include <queue>
using namespace std;
long long a[400005] = {0};
signed main()
{
    long long num, mouth, maxx = 0, sum = 0;
    queue<long long> myque;
    scanf("%lld%lld", &num, &mouth);
    for (int i = 1; i <= num; i++)
    {
        scanf("%lld", &a[i]);
        a[i + num] = a[i];
    }
    if (mouth > num)
        mouth = num;
    num = num * 2 - 1;

    for (int i = 1; i <= num; i++)
    {

        if (myque.size() + 1 > mouth)
        {
            sum -= myque.front();
            myque.pop();
        }

        if (sum <= 0)
        {
            while (myque.size() > 0)
            {
                myque.pop();
            }
            sum = 0;
        }

        if (sum > maxx)
            maxx = sum;

        myque.push(a[i]);
        sum += a[i];

        if (sum <= 0)
        {
            while (myque.size() > 0)
            {
                myque.pop();
            }
            sum = 0;
        }

        if (sum > maxx)
            maxx = sum;
    }

    printf("%lld", max((long long)0, maxx));
    return 0;
}