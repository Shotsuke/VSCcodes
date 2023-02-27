#include <iostream>
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <cstring>
#include <string.h>
using namespace std;
int main()
{
    int t;
    long long a, b, c;
    long long jx = 0, jy = 0, jz = 0;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        scanf("%lld%lld%lld", &a, &b, &c);
        bool flag = false;
        for (jx = 1; jx * jx * jx <= b; jx++)
        {
            if (flag == true)
                break;
            else
            {
                if (b % jx != 0)
                    continue;
                else
                {
                    for (jy = jx; jy * jy * jx <= b; jy++)
                    {
                        if ((b / jx) % jy != 0)
                            continue;
                        else
                        {
                            jz = b / jx / jy;
                            if (jx + jy + jz != a)
                                continue;
                            else
                            {
                                if (jx * jx + jy * jy + jz * jz != c)
                                    continue;
                                else
                                {
                                    flag = true;
                                    printf("%lld %lld %lld\n", jx, jy, jz);
                                }
                            }
                        }
                    }
                }
            }
        }
        if (flag == false)
            printf("Failed\n");
    }
    return 0;
}