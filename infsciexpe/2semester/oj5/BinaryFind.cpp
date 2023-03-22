#include <iostream>
using namespace std;

int binaryFind_firstMoreAndEqual(int n_num , int arr[] , int x)
{
    int l = 0 , r = n_num;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] < x)   l = mid + 1;
        else                r = mid;
    }
    return r;
}
int binaryFind_lastLessAndEqual(int n_num , int arr[] , int x)
{
    int l = -1 , r = n_num - 1;
    while (l < r)
    {
        int mid = (l + r + 1) / 2;
        if (arr[mid] <= x)  l = mid;
        else                r = mid - 1;
    }
    return r;
}
signed  main()
{
    int n_num , q_reqs , num , arr[1000] = {0};
    cin>>n_num;
    for(int i=0 ; i<n_num ; ++i)
    {
        cin>>arr[i];
    }

    cin>>q_reqs;
    for(int i=0 ; i<q_reqs ; ++i)
    {
        cin>>num;
        cout<<binaryFind_firstMoreAndEqual(n_num , arr , num)
            <<" "
            <<binaryFind_lastLessAndEqual(n_num , arr , num)
            <<endl;
    }

    return 0;
}