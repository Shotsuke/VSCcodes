#include <iostream>
#include <stdio.h>

using namespace std;
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n%d", a + b, a * b);
    std::cout << a + b << std::endl
              << a * b << std::endl; //表示引用在std命名空间里的函数
    return 0;
}