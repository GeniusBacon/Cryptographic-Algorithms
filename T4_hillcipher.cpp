#include <iostream>
#include <math.h>
#include "T4_HillCipher.h"

using namespace std;

vector<int> T4_HillCipher::Encrypt(vector<int> p, vector<int> k)
{
    vector<int> c;
    int root = (int)sqrt(k.size());
    int d = get_matrix_determinent(k);
    while (d < 0)
        d += 26;
    if (d % 2 == 0 || d % 13 == 0 || d == 0)
    {
        cout << "Invalid key matrix\n";
        return {};
    }
    while (p.size() % root)
        p.push_back(25);
    int size = p.size();
    for (int i = 0; i < size; i += root)
        for (int j = 0; j < root; j++)
        {
            int tmp = 0;
            for (int z = 0; z < root; z++)
                tmp += (p[i + z] * k[(j*root) + z]);
            while (tmp < 0)
                tmp += 26;
            tmp %= 26;
            c.push_back(tmp);
            cout << tmp << ' ';
        }
    return c;
}

vector<int> T4_HillCipher::Decrypt(vector<int> c, vector<int> k)
{
    vector<int> p;
    int size = p.size();
    int d = get_matrix_determinent(k);
    while (d < 0)
        d += 26;
    if (d % 2 == 0 || d % 13 == 0 || d == 0)
    {
        cout << "Invalid key matrix\n";
        return {};
    }
    if (size % (int)sqrt(k.size()))
    {
        cout << "Invalid plaintext size\n";
        return {};
    }
    k = get_matrix_inverse(k);
    p = Encrypt(c, k);
    return p;
}

vector<int> T4_HillCipher::get_matrix_inverse(vector<int> m)
{
    int d = get_matrix_determinent(m), size = m.size();
    while (d < 0)
        d += 26;
    vector<int> adjucate = get_matrix_adjucate(m);
    int MI = modular_multiplicative_inverse(d, 26);
    for (int i = 0; i < size; i++)
    {
        adjucate[i] *= MI;
        while (adjucate[i] < 0)
            adjucate[i] += 26;
        adjucate[i] %= 26;
    }
    m = get_matrix_transpose(adjucate);
    return m;
}

vector<int> T4_HillCipher::get_matrix_transpose(vector<int> m)
{
    int size = sqrt(m.size());
    /*if (size == 2)
        swap(m[1], m[2]);*/
    if (size == 3)
    {
        swap(m[1], m[3]);
        swap(m[2], m[6]);
        swap(m[5], m[7]);
    }
    return m;
}

int T4_HillCipher::modular_multiplicative_inverse(int d, int mod)
{
    int tmp = 1;
    while (((d * tmp) % mod) != 1)
        tmp++;
    return tmp;
}

vector<int> T4_HillCipher::get_matrix_adjucate(vector<int> m)
{
    int s = sqrt(m.size());
    if (s == 2)
    {
        swap(m[0], m[3]);
        m[1] *= -1;
        m[2] *= -1;
    }
    else if (s == 3)
    {
        int arr[9];
        arr[0] = ((m[4] * m[8]) - (m[5] * m[7]));
        arr[1] = (-1 * ((m[3] * m[8]) - (m[5] * m[6])));
        arr[2] = ((m[3] * m[7]) - (m[4] * m[6]));
        arr[3] = (-1 * ((m[1] * m[8]) - (m[2] * m[7])));
        arr[4] = ((m[0] * m[8]) - (m[2] * m[6]));
        arr[5] = (-1 * ((m[0] * m[7]) - (m[1] * m[6])));
        arr[6] = ((m[1] * m[5]) - (m[2] * m[4]));
        arr[7] = (-1 * ((m[0] * m[5]) - (m[2] * m[3])));
        arr[8] = ((m[0] * m[4]) - (m[1] * m[3]));
        for (int i = 0; i < 9; i++)
            m[i] = arr[i];
    }
    return m;
}

int T4_HillCipher::get_matrix_determinent(vector<int> m)
{
    int s = m.size();
    int d = -1;
    if (s == 4)
        d = (m[0] * m[3]) - (m[1] * m[2]);
    else if (s == 9)
        d = (m[0] * ((m[4] * m[8]) - (m[5] * m[7])) -
            m[1] * ((m[3] * m[8]) - (m[5] * m[6])) +
            m[2] * ((m[3] * m[7]) - (m[4] * m[6])));
    else cout << " invalid matrix size \n ";
    return d;
}

vector<int> T4_HillCipher::Analyse_key2(vector<int> p, vector<int> c)
{
    if (p.size() % 2 || p.size() < 4)
    {
        cout << "Invalid size of plaintext\n";
        return {};
    }
    for (int i = 0; i < p.size(); i += 2)
    {
        vector<int> plain = { p[i], p[i + 1] };
        for (int j = i + 2; j < p.size(); j += 2)
        {
            plain.push_back(p[j]);
            plain.push_back(p[j + 1]);
            int d = get_matrix_determinent(plain);
            while (d < 0)
                d += 26;
            if (!(d % 2 == 0 || d % 13 == 0 || d == 0))
            {
                vector<int> pinv = get_matrix_inverse(plain);
                vector<int> cipher = { c[i], c[i + 1], c[j], c[j + 1] };
                vector<int> k = square_matrix_multiplication(pinv, cipher);
                for (int i = 0; i < k.size(); i++)
                    k[i] %= 26;



                return k;
            }
            plain.pop_back();
            plain.pop_back();
        }
        plain.pop_back();
        plain.pop_back();
    }
    cout << "The plaintext couldn't be reversed.\n";
    return {};
}

vector<int> T4_HillCipher::square_matrix_multiplication(vector<int> a, vector<int> b)
{
    if (a.size() != b.size())
    {
        cout << "Matrices are not of equal size.\n";
        return {};
    }
    vector<int> res;
    if (a.size() == 4)
    {
        res = { (a[0] * b[0]) + (a[1] * b[2]), (a[0] * b[1]) + (a[1] * b[3]), (a[2] * b[0])
            + (a[3] * b[2]), (a[2] * b[1]) + (a[3] * b[3]) };
    }
    else if (a.size() == 9)
    {
        res = { (a[0] * b[0]) + (a[1] * b[3]) + (a[2] * b[6]),
            (a[0] * b[1]) + (a[1] * b[4]) + (a[2] * b[7]),
            (a[0] * b[2]) + (a[1] * b[5]) + (a[2] * b[8]),
            (a[3] * b[0]) + (a[4] * b[3]) + (a[5] * b[6]),
            (a[3] * b[1]) + (a[4] * b[4]) + (a[5] * b[7]),
            (a[3] * b[2]) + (a[4] * b[5]) + (a[5] * b[8]),
            (a[6] * b[0]) + (a[7] * b[3]) + (a[8] * b[6]),
            (a[6] * b[1]) + (a[7] * b[4]) + (a[8] * b[7]),
            (a[6] * b[2]) + (a[7] * b[5]) + (a[8] * b[8]) };
    }
    return res;
}

vector<int> T4_HillCipher::Analyse_key3(vector<int> p, vector<int> c)
{
    if (p.size() % 3 || p.size() < 9)
    {
        cout << "Invalid size of plaintext\n";
        return {};
    }
    for (int i = 0; i < p.size(); i += 3)
    {
        vector<int> plain = { p[i], p[i + 1], p[i + 2] };
        for (int j = i + 3; j < p.size(); j += 3)
        {
            plain.push_back(p[j]);
            plain.push_back(p[j + 1]);
            plain.push_back(p[j + 2]);

            for (int z = j + 3; z < p.size(); z += 3)
            {
                plain.push_back(p[z]);
                plain.push_back(p[z + 1]);
                plain.push_back(p[z + 2]);

                int d = get_matrix_determinent(plain);
                while (d < 0)
                    d += 26;
                if (!(d % 2 == 0 || d % 13 == 0 || d == 0))
                {
                    vector<int> pinv = get_matrix_inverse(plain);
                    vector<int> cipher = { c[i], c[i + 1], c[i + 2], c[j], c[j + 1], c[j + 2], c[z], c[z + 1], c[z + 2] };
                    vector<int> k = square_matrix_multiplication(pinv, cipher);
                    for (int i = 0; i < k.size(); i++)
                        k[i] %= 26;
                    return k;
                }
                plain.pop_back();
                plain.pop_back();
                plain.pop_back();
            }
            plain.pop_back();
            plain.pop_back();
            plain.pop_back();
        }
        plain.pop_back();
        plain.pop_back();
        plain.pop_back();
    }
    cout << "The plaintext couldn't be reversed.\n";
    return {};
    return {};
}
