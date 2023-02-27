#include <iostream>
#include <stdio.h>
#include <cmath>
#include <queue>
using namespace std;
long long a[400005] = {0};
long long s[400005] = {0};
signed main()
{

    long long num, mouth, maxx = 0, sum = 0;
    deque<long long> myque;
    scanf("%lld%lld", &num, &mouth);
    for (int i = 1; i <= num; i++)
    {
        scanf("%lld", &a[i]);
        s[i] = s[i - 1] + a[i];
    }
    for (int i = num + 1; i <= num * 2 - 1; i++)
    {
        a[i] = a[i - num];
        s[i] = s[i - 1] + a[i];
    }
    num = num * 2 - 1;

    for (int i = 1; i <= num; i++)
    {
        if (!myque.empty() && myque.front() < i - mouth)
            myque.pop_front();
        while (!myque.empty() && s[myque.back()] > s[i])
            myque.pop_back();
        myque.push_back(i);
        /*if (i >= mouth)
        {
            printf("[%d,%d]min=%lld\n", i - mouth + 1, i, myque.front());
        }*/
        maxx = max(s[i] - s[myque.front()], maxx);
    }

    printf("%lld", max((long long)0, maxx));

    return 0;
}
