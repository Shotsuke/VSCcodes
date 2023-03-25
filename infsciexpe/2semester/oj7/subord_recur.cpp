#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class staff
{
    int id;
    int sup;

public:
    int intodeg;
    int intosum;

    staff()
    {
        this->id = 0;
        this->sup = 0;
        this->intosum = 0;
        this->intodeg = 0;
    }
    void staffChange(int _id, int _sup)
    {
        this->id = _id;
        this->sup = _sup;
    }
    friend vector<int> toposort(int size, staff stf[]);
    friend void intodegSumUp(int id, int x, staff stf[]);
    ~staff()
    {
    }
};
vector<int> topo;
vector<int> toposort(int size, staff stf[])
{
    vector<int> topo;
    queue<int> myQue;
    for (int i = 0; i < size; ++i)
    {
        if (stf[i].intodeg == 0)
            myQue.push(i);
    }
    while (!myQue.empty())
    {
        int u = myQue.front();
        myQue.pop();
        topo.push_back(u);
        if (--stf[stf[u].sup].intodeg == 0)
        {
            myQue.push(stf[u].sup);
        }
    }
    return topo;
}
void intodegSumUp(int id, int x, staff stf[])
{
    stf[stf[id].sup].intosum += x + 1;
}
signed main()
{
    int n;
    cin >> n;
    staff *stf = new staff[n];
    for (int i = 0; i < n; ++i)
    {
        int sup;
        cin >> sup;
        stf[i].staffChange(i, sup);
        stf[sup].intodeg += 1;
        /*   For the question1.
         *   if (i != n - 1)
         *   {
         *       stf[sup].intoSumup(stf[i].myIntoSum());
         *   }
         *   cout << stf[i].myIntoSum() << " ";
         */
    }
    topo = toposort(n, stf);
    for (auto iter : topo)
    {
        intodegSumUp(iter, stf[iter].intosum, stf);
    }
    for (int i = 0; i < n; ++i)
    {
        cout << stf[i].intosum << " ";
    }
    return 0;
}