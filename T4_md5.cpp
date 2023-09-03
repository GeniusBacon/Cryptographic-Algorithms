#include "T4_md5.h"
#include <iostream>
#include <string>
#include <bitset>
using namespace std;

string T4_md5::GetHash(string text)
{
    text = Padding(text);                   // Binarize the string and do padding + length
    string CV = A + B + C + D;              // Initialization vectors
    for (int i = 0; i < text.size(); i += 512)
    {
        string current_text = text.substr(i, 512);		// Each 512-bit block
        CV = H_md5(current_text, CV);
    }
    string a = LittleEndian(CV.substr(0, 8), 0), b = LittleEndian(CV.substr(8, 8), 0);
    string c = LittleEndian(CV.substr(16, 8), 0), d = LittleEndian(CV.substr(24, 8), 0);

    string cipher = a + b + c + d;
    return cipher;
}

string T4_md5::Padding(string Plain)
{
    string BinaryPlain = string_to_binary(Plain);
    long long L = BinaryPlain.size();
    BinaryPlain += "1";
    while (BinaryPlain.size() % 512 != 448)
        BinaryPlain += "0";
    string Length = bitset<64>(L).to_string();
    BinaryPlain += LittleEndian(Length, 1);
    return BinaryPlain;
}

string T4_md5::string_to_binary(string s)
{
    string res = "";
    for (int i = 0; i < s.size(); i++)
    {
        int Num = (int)s[i];
        res += (bitset<8>(Num).to_string());
    }
    return res;
}

string T4_md5::H_md5(string Y, string CV)
{
    string a = CV.substr(0, 8), b = CV.substr(8, 8);
    string c = CV.substr(16, 8), d = CV.substr(24, 8);
    string a_tmp = a, b_tmp = b, c_tmp = c, d_tmp = d;

    string x[16];
    for (int i = 0; i < 16; i++)						// Divide the block into 16 piece, each 16-bit
        x[i] = Binary2Hexa(Y.substr(32 * i, 32));

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            string RoundFunction;
            if (i == 0)
                RoundFunction = F_Func(b, c, d);
            else if (i == 1)
                RoundFunction = G_Func(b, c, d);
            else if (i == 2)
                RoundFunction = H_Func(b, c, d);
            else if (i == 3)
                RoundFunction = I_Func(b, c, d);

            RoundFunction = Binary2Hexa(RoundFunction);
            string tmp = b;
            b = HexAddition(RoundFunction, a);
            b = HexAddition(b, LittleEndian(x[x_order[i][j]], 0));
            b = HexAddition(b, T[i][j]);

            b = Hexa_to_Binary(b);
            b = circular_shift(b, 1, s_order[i][j]);
            b = Binary2Hexa(b);

            b = HexAddition(b, tmp);
            a = d;
            d = c;
            c = tmp;
        }
    }
    a = HexAddition(a_tmp, a);
    b = HexAddition(b_tmp, b);
    c = HexAddition(c_tmp, c);
    d = HexAddition(d_tmp, d);

    CV = a + b + c + d;
    return CV;
}


string T4_md5::F_Func(string b, string c, string d)
{
    string x = Hexa_to_Binary(b);
    string y = Hexa_to_Binary(c);
    string z = Hexa_to_Binary(d);

    string andRes1 = AND(x, y);
    string andRes2 = AND(NOT(x), z);
    string orRes = OR(andRes1, andRes2);

    return orRes;
}
string T4_md5::G_Func(string b, string c, string d)
{
    string x = Hexa_to_Binary(b);
    string y = Hexa_to_Binary(c);
    string z = Hexa_to_Binary(d);

    string andRes1 = AND(x, z);
    string andRes2 = AND(y, NOT(z));
    string orRes = OR(andRes1, andRes2);

    return orRes;
}
string T4_md5::H_Func(string b, string c, string d)
{
    string x = Hexa_to_Binary(b);
    string y = Hexa_to_Binary(c);
    string z = Hexa_to_Binary(d);

    string final_H = XOR(x, XOR(y, z));
    return final_H;
}
string T4_md5::I_Func(string b, string c, string d)
{
    string x = Hexa_to_Binary(b);
    string y = Hexa_to_Binary(c);
    string z = Hexa_to_Binary(d);

    string orRes = OR(x, NOT(z));
    string xorRes = XOR(y, orRes);

    return xorRes;
}

string T4_md5::Hexa_to_Binary(string s)
{
    string res;
    for (int i = 0; i < s.size(); i++)
    {
        s[i] = toupper(s[i]);
        int n = decimal_of_hex[(int)s[i]];
        string bin = bitset<4>(n).to_string();
        res += bin;
    }
    return res;
}

string T4_md5::XOR(string first, string second)
{
    string output = first;
    for (int k = 0; k < first.size(); k++)
        if (first[k] == second[k])
            output[k] = '0';
        else
            output[k] = '1';
    return output;
}
string T4_md5::AND(string first, string second)
{
    string output = first;
    for (int k = 0; k < first.size(); k++)
        if (first[k] == '1' && second[k] == '1')
            output[k] = '1';
        else
            output[k] = '0';
    return output;
}
string T4_md5::OR(string first, string second)
{
    string output = first;
    for (int k = 0; k < first.size(); k++)
        if (first[k] == '0' && second[k] == '0')
            output[k] = '0';
        else
            output[k] = '1';
    return output;
}
string T4_md5::NOT(string s)
{
    string output = s;
    for (int k = 0; k < s.size(); k++)
        if (s[k] == '0')
            output[k] = '1';
        else
            output[k] = '0';
    return output;
}

string T4_md5::HexAddition(string a, string b)
{
    a = Hexa_to_Binary(a);
    b = Hexa_to_Binary(b);
    long long sum = Binary2Decimal(a) + Binary2Decimal(b);
    sum %= 4294967296;
    string res = decimal2Hexa(sum);
    while (res.size() < 8)
        res.insert(res.begin(), '0');
    return res;
}

long long T4_md5::Binary2Decimal(string S)
{
    long long n = 0, cnt = 0;
    for (int i = S.size() - 1; i >= 0; i--)
    {
        long long p = pow(2, cnt++);
        int bit = (int)S[i] - 48;
        n += (p * bit);
    }
    return n;
}

string T4_md5::decimal2Hexa(long long n)
{
    string res = "";
    while (n != 0)
    {
        long long rem = n % 16;
        n /= 16;
        res += hex_of_decimal[rem];
    }
    reverse(res.begin(), res.end());
    return res;
}

string T4_md5::Binary2Hexa(string s)
{
    string result = "";
    for (int i = 0; i < s.size(); i += 4)
    {
        int n = Binary2Decimal(s.substr(i, 4));
        result += hex_of_decimal[n];
    }
    return result;
}

string T4_md5::circular_shift(string S, bool left, int bits)
{
    while (bits--)
    {
        if (left)
        {
            S += S[0];
            S.erase(S.begin());
        }
        else					// right shift not needed
        {
            S.insert(S.begin(), S[S.size() - 1]);
            S.erase(S.end() - 1);
        }
    }
    return S;
}

string T4_md5::LittleEndian(string s, bool binary)
{
    string res = "";
    if (!binary)				// Hexa
    {
        for (int i = s.size() - 2; i >= 0; i -= 2)
            res += (s.substr(i, 2));
    }
    else
    {
        for (int i = s.size() - 8; i >= 0; i -= 8)
            res += (s.substr(i, 8));
    }
    return res;
}
