#include <bits/stdc++.h>
using namespace std;
inline int getint()
{
    int ssum = 0, ff = 1;
    char ch;
    for (ch = getchar(); !isdigit(ch) && ch != '-'; ch = getchar())
        ;
    if (ch == '-')
        ff = -1, ch = getchar();
    for (; isdigit(ch); ch = getchar())
        ssum = ssum * 10 + ch - '0';
    return ssum * ff;
}

const int M = 2e6 + 5;
int n, m, a[M];
bool is[M];
double f[M], p[M];
int q[M], l = 1, r;

void Solve()
{

    int up = (1 << n) - 1;
    is[up] = 1;
    f[up] = 0;
    q[++r] = up;

    for (int j = up - 1; j >= 0; j--)
    {

        int now = j; //	cout<<now<<": ";

        if (now != up)
        {

            double sum = 0;
            for (int i = 1; i <= m; i++)
            {

                int nxt = (now | a[i]); // cout<<nxt<<"#"<<endl;
                if (nxt == now)
                {

                    sum += p[i];
                }
                else
                {

                    f[now] += p[i] * (1.0 + f[nxt]);
                }
            }

            if (fabs(sum - 1.0) < 1e-7)
            {

                cout << -1;
                return;
            }

            f[now] += sum;
            f[now] /= (1.0 - sum);
        }
        //	cout<<f[now]<<endl;
    }

    printf("%0.6lf", f[0]);
    return;
}

signed main()
{

    //	freopen("1.in","r",stdin);

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {

        a[i] = getint();

        scanf("%lf", &p[i]);
    }

    Solve();

    return 0 - 0;
}