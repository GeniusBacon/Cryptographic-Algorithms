#include "T4_Caesar.h"
#include <iostream>
#include <math.h>
using namespace std;

string T4_Caesar::Encrypt(string p, int k)
{
    string c = p;
    for (int i = 0; i < p.size(); i++)
    {
        p[i] = tolower(p[i]);
        if (p[i] < 'a' || p[i] > 'z')
        {
            c[i] = p[i];
            continue;
        }
        c[i] = 'a' + mod((p[i] - 'a' + k), 26);
        c[i] = toupper(c[i]);
    }
    return c;
}

string T4_Caesar::Decrypt(string c, int k)
{
    string p = c;
    for (int i = 0; i < c.size(); i++)
    {
        c[i] = tolower(c[i]);
        if (c[i] < 'a' || c[i] > 'z')
        {
            p[i] = c[i];
            continue;
        }

        p[i] = 'a' + ((c[i] - 'a' - k) % 26);
        p[i] = 'a' + mod((c[i] - 'a' - k), 26);			// edit 1: mod function for negative numbers			Input Validaiton
        }
    return p;
}

int T4_Caesar::Analyze(string p, string c)
{
    int counter = 0;
    char r = tolower(c[0]);
    for (char l = tolower(p[0]); l != r; l++)			// edit 2 :	toLower for capital/small letters			Input Validation
    {
        counter++;
        if (l == 'z')
            l = 'a' - 1;
    }
    return counter;
}

long long T4_Caesar::mod(long long n, long long m)
{
    while (n < 0)
        n += m;
    n %= m;
    return n;
}
