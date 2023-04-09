#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    int *a, l, r;
    Node(int *_a, int _l, int _r)
    {
        a = _a;
        l = _l;
        r = _r;
    }
};

int Partition(int a[], int l, int r)
{
    int x = a[(l + r) / 2];
    int i = l - 1, j = r + 1;
    while (i < j)
    {
        do
            i++;
        while (a[i] < x);
        do
            j--;
        while (a[j] > x);
        if (i < j)
            swap(a[i], a[j]);
    }
    return j;
}

void quicksort(int a[], int l, int r)
{
    stack<int> s;
    s.push(l);
    s.push(r);
    while (!s.empty())
    {
        int right = s.top();
        s.pop();
        int left = s.top();
        s.pop();
        if (left < right)
        {
            int p = Partition(a, left, right);
            s.push(left);
            s.push(p);
            s.push(p + 1);
            s.push(right);
        }
    }
}

signed main()
{
    int n;
    cin >> n;
    int a[1000] = {0};
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    quicksort(a, 0, n - 1);
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    return 0;
}