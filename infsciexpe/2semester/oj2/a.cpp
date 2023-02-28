#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;
signed main()
{
    int theMaxLength[1000], maxLength = 1;
    for (int i = 0; i < 1000; ++i)
    {
        theMaxLength[i] = 1;
    }
    int sequence[1000] = {0};
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> sequence[i];
        for (int j = 0; j < i; ++j)
        {
            if (sequence[i] > sequence[j])
            {
                theMaxLength[i] = max(theMaxLength[i], theMaxLength[j] + 1);
                maxLength = max(maxLength, theMaxLength[i]);
            }
        }
    }
    stack<int> answ;
    cout << maxLength << endl;
    for (int i = n - 1; i >= 0; --i)
    {
        if (maxLength == 0)
        {
            break;
        }
        else if (theMaxLength[i] == maxLength && answ.empty())
        {
            maxLength--;
            answ.push(sequence[i]);
        }
        else if (theMaxLength[i] == maxLength && !answ.empty() && sequence[i] < answ.top())
        {
            maxLength--;
            answ.push(sequence[i]);
        }
    }
    while (!answ.empty())
    {
        cout << answ.top() << " ";
        answ.pop();
    }
    return 0;
}