#include <stdio.h>
int sq(int x)
{
    return x * x;
}
int sum(int start, int end, int (*f)(int t))
{
    int temp = 0;
    for (int i = start; i <= end; i++)
    {
        temp = temp + f(i);
    }
    return temp;
}
int main()
{
    int x, y;
    scanf_s("%d %d", &x, &y);
    printf("%d", sum(x, y, sq));
    return 0;
}