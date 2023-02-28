#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;
struct Sequence
{
    int _val;
    int _maxLength;
    int _maxSum;
    int _pre;
    Sequence()
    {
        _pre = -1;
        _maxLength = 1;
    }
};
signed main()
{
    Sequence seq[1000];
    int n, anssum = 0, anslen = 1;
    cin >> n;
    seq[n]._val = 99999;
    for (int i = 0; i <= n; ++i)
    {
        if (i != n)
            cin >> seq[i]._val;
        seq[i]._maxSum = seq[i]._val;
        for (int j = 0; j < i; ++j)
        {
            if (seq[i]._val > seq[j]._val)
            {
                if (seq[i]._maxLength < seq[j]._maxLength + 1)
                {
                    seq[i]._maxLength = seq[j]._maxLength + 1;
                    seq[i]._maxSum = seq[j]._maxSum + seq[i]._val;
                    seq[i]._pre = j;
                }
                else if (seq[i]._maxLength == seq[j]._maxLength + 1)
                {
                    if (seq[i]._maxSum <= seq[j]._maxSum + seq[i]._val)
                    {
                        seq[i]._maxSum = seq[j]._maxSum + seq[i]._val;
                        seq[i]._pre = j;
                    }
                }
            }
        }
    }
    cout << seq[n]._maxLength - 1 << endl;
    stack<int> ansseq;
    while (seq[n]._pre != -1)
    {
        n = seq[n]._pre;
        ansseq.push(seq[n]._val);
    }
    while (!ansseq.empty())
    {
        cout << ansseq.top() << " ";
        ansseq.pop();
    }
    return 0;
}