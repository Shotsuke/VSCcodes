#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
signed main()
{
    int n = 8;
    int *p1 = (int *)malloc(sizeof(int) * n);
    int *p2 = new int[n];
    free(p1);
    delete[] p2;
    int(*q)[20];
    q = new int[n][20];
    delete[] q;
    return 0;
}