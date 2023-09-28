#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
signed main()
{
    string data[100];
    int n;
    int ans[100] = {1};
    cin>>n;
    for(int i = 0 ; i < n ; ++i)
    {
        for(int j = 0 ; j < 8 ; ++j)
        {
            string temp;
            cin>>temp;
            data[i] += temp;
        }
    }
    for(int i = 0 ; i < n ; ++i)
    {
        for(int j = i-1 ; j >= 0 ; --j)
        {
            if(data[i] == data[j])
            {
                ans[i] = ans[j]+1;
                break;
            }
            if(j == 0)
            {
                ans[i] = 1;
            }
        }
    }
    for(int i =0  ; i < n ; ++i)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}