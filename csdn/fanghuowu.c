
// 请关闭中文输入法，用英文的字母和标点符号。
// 如果你想运行系统测试用例，请点击【执行代码】按钮，如果你想提交作答结果，请点击【提交】按钮，
// 注意：除答案外，请不要打印其他任何多余的字符，以免影响结果验证
// 本OJ系统是基于 OxCoder 技术开发，网址：www.oxcoder.com
// 模版代码提供基本的输入输出框架，可按个人代码习惯修改

#include <stdio.h>

int solution(int n, int k)
{
    int result;
    if (k < 13)
    {
        int t;
        if (n % k == 0)
            t = 0;
        else
            t = 1;
        result = n / k + t;
    }
    if (k == 13)
    {
        int t;
        if (n % 12 == 0)
            t = 0;
        else
            t = 1;
        result = n / 12 + t;
    }
    if (k > 13)
    {
        int t;
        if (n % k == 0)
            t = 0;
        else
            t = 1;
        if (n % k == 13)
        {
            if (k == 14)
                t++;
        }
        result = n / k + t;
    }
    return result;
}

int main()
{

    int n, k;
    while (scanf("%d %d", &n, &k) != EOF)
    {
        int result;
        result = solution(n, k);
        printf("%d\n", result);
    }
    return 0;
}