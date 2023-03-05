#include <iostream>
#include <cstring>
using namespace std;

class Element
{
public:
    long long _val;
    int _key[64];
    int _digit;
    Element();
    void Init(long long x);
    ~Element();
    // bool operator<(const Element &y)
    // {
    //     for (int i = 0; i < max(_digit, y._digit); ++i)
    //     {
    //         if (_key[i] == y._key[i])
    //             continue;
    //         return _key[i] < y._key[i];
    //     }
    //     return false;
    // }
} arr[1000], cpy[1000];
Element::Element()
{
    _digit = 0;
    for (int i = 0; i < 64; ++i)
    {
        _key[i] = 0;
    }
    _val = 0;
}

void Element::Init(long long x)
{
    _val = x;
    int digit = 0;
    while (x > 0)
    {
        _key[digit] = x % 10;
        x /= 10;
        digit++;
    }
    _digit = digit;
}

Element::~Element()
{
}

void digitSort(long long n, long long p)
{
    int cnt[10] = {-1};
    for (int i = 0; i < n; ++i)
    {
        ++cnt[arr[i]._key[p]];
    }
    for (int i = 1; i < 10; ++i)
    {
        cnt[i] += cnt[i - 1];
    }
    for (int i = n - 1; i >= 0; --i)
    {
        cpy[cnt[arr[i]._key[p]]--] = arr[i];
    }
    memcpy(arr, cpy, sizeof(arr));
}

signed main()
{
    long long n;
    int k = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        long long x;
        cin >> x;
        arr[i].Init(x);
        k = max(k, arr[i]._digit);
    }

    for (int i = 0; i < k; ++i)
    {
        digitSort(n, i);
    }

    for (int i = 0; i < n; ++i)
    {
        cout << arr[i]._val << " ";
    }

    return 0;
}