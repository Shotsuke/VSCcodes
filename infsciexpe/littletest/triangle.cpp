#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    printf("+\n");
    for (int i = 2; i <= n - 1; i++)
    {
        printf("|");
        for (int j = 2; j <= i - 1; j++)
        {
            printf(" ");
        }
        printf("\\\n");
    }
    printf("+");
    for (int i = 2; i <= n - 1; i++)
    {
        printf("-");
    }
    printf("+");
}