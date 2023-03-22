#include <iostream>
#include <string.h>
using namespace std;

void mergeSort( int list1[] , int list2[] , int list3[],
                int l1      , int r1 ,
                int l2      , int r2 , int s)
{
    if(l1 == r1) 
    {
        memcpy(&list3[s] , &list2[l2] , (r2 - l2)*sizeof(int));
    }
    else if (l2 == r2)
    {
        memcpy(&list3[s] , &list1[l1] , (r1 - l1)*sizeof(int));
    }
    else 
    {
        if(list1[l1] < list2[l2])
        {
            list3[s] = list1[l1];
            mergeSort(list1 , list2 , list3 , 
                    l1+1 , r1 , l2 , r2 , s+1);
        }
        else 
        {
            list3[s] = list2[l2];
            mergeSort(list1 , list2 , list3 , 
                    l1 , r1 , l2+1 , r2 , s+1);
        }
    }
    return ;
}
signed main() 
{
    int length_List1 , length_List2 ,length_List3 = 0;
    cin>>length_List1;
    int *list1 = new int[length_List1];
    for(int i=0 ; i<length_List1 ; ++i)
    {
        cin>>list1[i];
    }
    cin>>length_List2;
    length_List3 = length_List1 + length_List2;
    int *list2 = new int[length_List2];
    int *list3 = new int[length_List3];
    for(int i=0 ; i<length_List2 ; ++i)
    {
        cin>>list2[i];
    }
    mergeSort(list1 , list2 , list3 ,
                0 , length_List1 , 0 , length_List2 , 0);
    for(int i=0 ; i<length_List3 ; ++i)
    {
        cout<<list3[i]<<" ";
    }
}