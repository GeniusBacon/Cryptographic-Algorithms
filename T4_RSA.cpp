#include "T4_RSA.h"
#include <iostream>
#include <numeric>
#include<math.h>
using namespace std;

int T4_RSA::rsa_keysetup(int p, int q)
{
    int e = 0;
    long long qn = ((long long)p - 1) * ((long long)q - 1);

    for (int i = 2; i < qn; i++)
    {
        if (i < qn && gcd(i, qn) == 1)
        {
            e = i;
            break;
        }
    }
    return e;
}

int T4_RSA::rsa_encrypt(int p, int q, int m)
{
    long long n = (long long)p * (long long)q;
    long long C = 0;
    long long e = rsa_keysetup(p, q);
    C = modular_power(m, e, n);
    return C;
}

int T4_RSA::rsa_decrypt(int p, int q, int c)
{
    long long n = (long long)p * (long long)q;
    long long M = 0;
    long long qn = ((long long)p - 1) * ((long long)q - 1);
    long long e = rsa_keysetup(p, q);
    long long d = modular_multiplicative_inverse(e, qn);

    M = modular_power(c, d, n);

    return M;
}

int T4_RSA::modular_multiplicative_inverse(int e, int qn)
{
    int d = 1;
    while (((e * d) % qn) != 1)
        d++;
    return d;
}
int T4_RSA::modular_power(int a, int b, int mod)
{
    // a^b  11^3 = 111111
    long long res = 1;
    for (int i = 1; i <= b; i++)
    {
        res *= a;
        res %= mod;
    }
    return res;
}

bool T4_RSA::isPrime(int n)
{
    for (int i = 2; i <= (int)sqrt(n); i++)
        if (n % i == 0)
            return 0;
    return 1;
}
