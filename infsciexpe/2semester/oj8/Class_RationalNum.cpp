#include <iostream>
#include <math.h>
using namespace std;
class Rational
{
private:
    long long a, b;
    long long gcd(long long m, long long n)
    {
        if (n == 0 && m == 0)
            return 1;
        while (m > 0 && n > 0)
        {
            if (m >= n)
                m %= n;
            else
                n %= m;
        }
        return n + m;
    }

public:
    Rational(long long _a, long long _b)
    {
        if (_b == 0)
        {
            printf("Divisor is 0.\n");
        }
        else if (_a == 0)
        {
            a = 0;
            b = 1;
        }
        else if (_b < 0)
        {
            a = -_a;
            b = -_b;
        }
        else
        {
            a = _a;
            b = _b;
        }
    }
    Rational()
    {
        a = 0;
        b = 1;
    }
    void resetMyself(long long _a, long long _b)
    {
        if (_b == 0)
        {
            printf("Divisor is 0.\n");
        }
        else if (_a == 0)
        {
            a = 0;
            b = 1;
        }
        else if (_b < 0)
        {
            a = -_a;
            b = -_b;
        }
        else
        {
            a = _a;
            b = _b;
        }
    }
    void showMyself()
    {
        printf("%d %d", a, b);
    }
    Rational operator+(Rational anotherValue)
    {
        long long ares = a * anotherValue.b + anotherValue.a * b;
        long long bres = b * anotherValue.b;
        long long gcdres = gcd(abs(ares), bres);
        ares /= gcdres;
        bres /= gcdres;
        return Rational(ares, bres);
    }
    Rational operator-(Rational anotherValue)
    {
        long long ares = a * anotherValue.b - anotherValue.a * b;
        long long bres = b * anotherValue.b;
        long long gcdres = gcd(abs(ares), bres);
        ares /= gcdres;
        bres /= gcdres;
        return Rational(ares, bres);
    }
    Rational operator*(Rational anotherValue)
    {
        long long ares = a * anotherValue.a;
        long long bres = b * anotherValue.b;
        long long gcdres = gcd(abs(ares), abs(bres));
        ares /= gcdres;
        bres /= gcdres;
        return Rational(ares, bres);
    }
    Rational operator/(Rational anotherValue)
    {
        long long ares = a * anotherValue.b;
        long long bres = b * anotherValue.a;
        long long gcdres = gcd(abs(ares), abs(bres));
        ares /= gcdres;
        bres /= gcdres;
        return Rational(ares, bres);
    }
};

class APlusBSqrt5
{
private:
    Rational r, q; // r for rational, q for sqrt(5)

public:
    APlusBSqrt5()
    {
    }
    APlusBSqrt5(Rational _r, Rational _q)
    {
        r = _r;
        q = _q;
    }
    APlusBSqrt5(long long r1, long long r2, long long q1, long long q2)
    {
        r.resetMyself(r1, r2);
        q.resetMyself(q1, q2);
    }
    void resetMyself(long long r1, long long r2, long long q1, long long q2)
    {
        r.resetMyself(r1, r2);
        q.resetMyself(q1, q2);
    }
    void showMyself()
    {
        r.showMyself();
        printf(" ");
        q.showMyself();
        printf("\n");
    }
    APlusBSqrt5 operator+(APlusBSqrt5 anotherValue)
    {
        Rational rres = r + anotherValue.r;
        Rational qres = q + anotherValue.q;
        return APlusBSqrt5(rres, qres);
    }
    APlusBSqrt5 operator-(APlusBSqrt5 anotherValue)
    {
        Rational rres = r - anotherValue.r;
        Rational qres = q - anotherValue.q;
        return APlusBSqrt5(rres, qres);
    }
    APlusBSqrt5 operator*(APlusBSqrt5 anotherValue)
    {
        Rational rres = r * anotherValue.r +
                        q * anotherValue.q * Rational(5, 1);
        Rational qres = r * anotherValue.q +
                        q * anotherValue.r;
        return APlusBSqrt5(rres, qres);
    }
    APlusBSqrt5 operator/(APlusBSqrt5 anotherValue)
    {
        Rational rres = (r * anotherValue.r -
                         Rational(5, 1) * q * anotherValue.q) /
                        (anotherValue.r * anotherValue.r -
                         Rational(5, 1) * anotherValue.q * anotherValue.q);
        Rational qres = (q * anotherValue.r - r * anotherValue.q) /
                        (anotherValue.r * anotherValue.r -
                         Rational(5, 1) * anotherValue.q * anotherValue.q);
        return APlusBSqrt5(rres, qres);
    }
};

signed main()
{
    long long n;
    cin >> n;
    for (long long i = 0; i < n; ++i)
    {
        long long ordi;
        scanf("%lld", &ordi);
        long long a, b, c, d, e, f, g, h;
        if (ordi == 0)
        {
            scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &a, &b, &c, &d, &e, &f, &g, &h);
            APlusBSqrt5 x(a, b, c, d), y(e, f, g, h);
            APlusBSqrt5 z = x + y;
            z.showMyself();
        }
        else if (ordi == 1)
        {
            scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &a, &b, &c, &d, &e, &f, &g, &h);
            APlusBSqrt5 x(a, b, c, d), y(e, f, g, h);
            APlusBSqrt5 z = x - y;
            z.showMyself();
        }
        else if (ordi == 2)
        {
            scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &a, &b, &c, &d, &e, &f, &g, &h);
            APlusBSqrt5 x(a, b, c, d), y(e, f, g, h);
            APlusBSqrt5 z = x * y;
            z.showMyself();
        }
        else if (ordi == 3)
        {
            scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &a, &b, &c, &d, &e, &f, &g, &h);
            APlusBSqrt5 x(a, b, c, d), y(e, f, g, h);
            APlusBSqrt5 z = x / y;
            z.showMyself();
        }
        else if (ordi == 4)
        {
            scanf("%lld%lld%lld%lld%lld", &a, &b, &c, &d, &e);
            APlusBSqrt5 x(a, b, c, d);
            APlusBSqrt5 z(1, 1, 0, 1);
            while (e > 0)
            {
                e--;
                z = z * x;
            }
            z.showMyself();
        }
    }
    return 0;
}
