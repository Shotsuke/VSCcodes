#include <iostream>
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <cstring>
#include <string.h>
using namespace std;
int a[100001] = {0};
int main()
{
    int t;
    int n;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        scanf("%d", &n);
        if (n <= 3)
            printf("-1\n");
        else if (n == 4)
            printf("9009\n");
        else if (n == 5)
            printf("18018\n");
        else if (n == 6)
            printf("108108\n");
        else if (n == 7)
            printf("1009008\n");
        else
        {
            printf("1");
            for (int k = n - 1; k >= 5; k--)
                printf("0");
            int j = (n - 2) % 6 + 1;
            if (j == 6)
                printf("9008\n");
            else if (j == 5)
                printf("8108\n");
            else if (j == 4)
                printf("8018\n");
            else if (j == 3)
                printf("8009\n");
            else if (j == 2)
                printf("8909\n");
            else if (j == 1)
                printf("8999\n");
        }
    }
    return 0;
}