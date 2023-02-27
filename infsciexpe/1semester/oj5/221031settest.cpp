#include <iostream>
#include <stdio.h>
#include <set>
using namespace std;
signed main()
{
    set<int> myset; //空set内无任何元素
    int x;
    printf("myset size = %d", (int)myset.size());
    for (int i = 1; i <= 5; i++)
    {
        scanf("%d", &x);
        myset.insert(x);
    }
    for (auto iter = myset.rbegin(); iter != myset.rend(); ++iter)
    {
        printf("%d ", *iter);
    }
    printf("%d", *myset.upper_bound(6));
    return 0;
}