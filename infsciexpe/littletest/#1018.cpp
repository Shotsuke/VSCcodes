#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
signed main()
{
    vector<int> vec;
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        vec.push_back(x);
    }
    vec.at(vec.size() - 1)--;
    for (int i = vec.size() - 1; i >= 1; i--)
    {

        if (vec.at(i) >= 0)
            break;
        else
        {
            vec.at(i) = 9;
            vec.at(i - 1)--;
        }
    }
    if (vec.at(0) == -1)
        vec.at(0) = 9;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vec.at(i));
    }
    return 0;
}