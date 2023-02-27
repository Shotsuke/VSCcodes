#include <iostream>
#include <stdio.h>
#include <string.h>
#define MOD 23333333
using namespace std;

struct matrix
{
    long long x[6][6];
    matrix() { memset(x, 0, sizeof(x)); }
};

matrix multiply(matrix &a, matrix &b)
{
    matrix c;
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            for (int k = 1; k <= 5; k++)
            {
                c.x[i][j] += (a.x[i][k] * b.x[k][j]) % MOD;
            }
            c.x[i][j] %= MOD;
        }
    }
    return c;
}

matrix mpow(matrix &a, long long m) //矩阵a的m次方
{
    matrix result;
    if (m < 0)
        return result;
    for (int i = 1; i <= 5; i++)
        result.x[i][i] = 1; //单位矩阵
    while (m > 0)
    {
        if (m & 1)
            result = multiply(a, result);
        a = multiply(a, a);
        m >>= 1;
    }
    return result;
}

signed main()
{
    long long l, r;
    matrix diedai;
    diedai.x[1][1] = diedai.x[1][2] = diedai.x[2][2] = 1;
    diedai.x[2][3] = diedai.x[2][4] = diedai.x[3][2] = 1;
    diedai.x[4][4] = diedai.x[4][5] = diedai.x[5][4] = 1;
    diedai.x[2][5] = 2;
    matrix diedaileft = diedai;
    matrix answer;
    answer.x[1][1] = answer.x[4][1] = answer.x[5][1] = 1;
    answer.x[2][1] = 2;
    answer.x[3][1] = 1;
    matrix answerleft = answer;
    scanf("%lld%lld", &l, &r);

    diedaileft = mpow(diedaileft, l - 2);
    diedai = mpow(diedai, r - 1);
    answerleft = multiply(diedaileft, answerleft);
    answer = multiply(diedai, answer);

    if (answer.x[1][1] >= answerleft.x[1][1])
        printf("%lld", answer.x[1][1] - answerleft.x[1][1]);
    else
        printf("%lld", MOD + answer.x[1][1] - answerleft.x[1][1]);
    return 0;
}