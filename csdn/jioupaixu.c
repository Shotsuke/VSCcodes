
// 请关闭中文输入法，用英文的字母和标点符号。
// 如果你想运行系统测试用例，请点击【执行代码】按钮，如果你想提交作答结果，请点击【提交】按钮，
// 注意：除答案外，请不要打印其他任何多余的字符，以免影响结果验证
// 本OJ系统是基于 OxCoder 技术开发，网址：www.oxcoder.com
// 模版代码提供基本的输入输出框架，可按个人代码习惯修改

#include <stdio.h>
#include <stdlib.h>

void solution(int m, int arr[])
{
    int b[m];
    int pb = -1;
    for (int i = 0; i < m; i++)
    {
        if (arr[i] % 2 == 1)
        {
            pb++;
            b[pb] = arr[i];
        }
    }
    for (int i = 0; i <= pb; i++)
    {
        printf("%d ", b[i]);
    }
    for (int i = 0; i < m; i++)
    {
        if (arr[i] % 2 == 0)
            printf("%d ", arr[i]);
    }
}

int main()
{

    int n;
    scanf("%d", &n);

    int *arr;
    arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    solution(n, arr);
    return 0;
}