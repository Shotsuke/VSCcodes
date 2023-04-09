#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    long long n, t1, t2, pos;

    Node(long long _n, long long _t1, long long _t2, long long _pos)
    {
        n = _n;
        t1 = _t1;
        t2 = _t2;
        pos = _pos;
    }
};

long long ret = 0;

signed main()
{
    int N;
    cin >> N;
    stack<Node> mystack;
    for (int i = 0; i < N; ++i)
    {
        long long n;
        cin >> n;
        mystack.push(Node(n, 0, 0, 0));
        while (!mystack.empty())
        {
            Node now = mystack.top();
            mystack.pop();
            switch (now.pos)
            {
            case 0:
            {
                if (now.n <= 1)
                {
                    ret = now.n;
                    continue;
                }
                else
                {
                    now.pos = 1;
                    mystack.push(now);
                    mystack.push(Node(now.n - 1, 0, 0, 0));
                    continue;
                }
            }
            case 1:
            {
                now.pos = 2;
                now.t1 = ret;
                mystack.push(now);
                mystack.push(Node(now.n - 2, 0, 0, 0));
                continue;
            }
            case 2:
            {
                now.t2 = ret;
                ret = now.t1 + now.t2;
                continue;
            }
            }
        }
        cout << ret << endl;
        ret = 0;
    }
    return 0;
}