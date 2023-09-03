#include "T4_AES.h"
#include <bitset>
using namespace std;
string T4_AES::Encrypt(string plain, string key)
{
    string Encryption;
    string keys[4][44];
    Key_Generation(key, keys);

    string p[4][4];
    int id = 0;
    for (int i = 0; i < 4; i++)					// plain from string to 2d
        for (int j = 0; j < 4; j++)
        {
            p[j][i] += toupper(plain[id++]);
            p[j][i] += toupper(plain[id++]);
        }

    AddRoundKey(p, 0, keys);            //  Initial Add Round Key

    int CurrentRoundIndex = 4;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
                p[j][k] = Sub_bytes(p[j][k], 0);            // sub bytes

        shiftRows(p, 1);                                    // shift rows

        if (i < 9)                                     // round 10 has no Mix Column operation
            mixcolumns(p);

        AddRoundKey(p, CurrentRoundIndex, keys);
        CurrentRoundIndex += 4;

    }
    for (int j = 0; j < 4; j++)
        for (int k = 0; k < 4; k++)
            Encryption += p[k][j];


    return Encryption;
}

string T4_AES::Decrypt(string cipher, string key)
{
    string Decryption;
    string c[4][4];
    int id = 0;
    for (int i = 0; i < 4; i++)					// cipher from 1d to 2d
        for (int j = 0; j < 4; j++)
        {
            c[j][i] += toupper(cipher[id++]);
            c[j][i] += toupper(cipher[id++]);
        }
    string keys[4][44];
    Key_Generation(key, keys);
    int CurrentRoundIndex = 40;
    for (int i = 0; i < 10; i++)         // 10
    {

        AddRoundKey(c, CurrentRoundIndex, keys);
        CurrentRoundIndex -= 4;

        if (i != 0)
        {
            inverseMixColumns(c);
        }

        shiftRows(c, 0);

        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
                c[j][k] = Sub_bytes(c[j][k], 1);
    }
    AddRoundKey(c, 0, keys);

    for (int j = 0; j < 4; j++)
        for (int k = 0; k < 4; k++)
            Decryption += c[k][j];


    return Decryption;
}






void T4_AES::splitString(string longstr, string sub[4])
{
    int counter = 0;
    for (int i = 0; i < longstr.size(); i++)
    {
        sub[counter] += longstr[i];
        if ((i + 1) % 8 == 0)
            counter++;
    }
}


void T4_AES::shiftRows(string sub[4][4], bool inverse)
{
    for (int i = 0; i < 4; i++)
    {
        string temp = "";
        for (int j = 0; j < 4; j++)
            temp += sub[i][j];
        circular_shift(temp, i, inverse);
        for (int j = 0; j < 4; j++)
            sub[i][j] = temp.substr(j * 2, 2);
    }
}


void T4_AES::mixcolumns(string plainhexa[4][4])
{
    string right[4];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            right[j] += plainhexa[i][j];
    for (int i = 0; i < 4; i++)
    {
        string left = Mixmatrix[i], products[4] = {};
        for (int j = 0; j < 4; j++)
        {
            int index = 0;
            for (int k = 0; k < 4; k++)
            {
                string bin = Hexa_to_Binary(right[j].substr(index, 2));
                char n = left[k];
                if (n == '2')
                {
                    mixCondition_Two(bin, products, k);
                }
                else if (n == '3')          // times 2, plus x (an additional xor)
                {
                    mixCondition_Three(bin, products, k);
                }
                else products[k] = bin;
                index += 2;
            }
            string block = XOR(XOR(XOR(products[0], products[1]), products[2]), products[3]);
            string first = block.substr(0, 4);
            string second = block.substr(4, 4);
            plainhexa[i][j] = {};
            plainhexa[i][j] += Binary2Hexa(first);
            plainhexa[i][j] += Binary2Hexa(second);
        }
    }
}

void T4_AES::inverseMixColumns(string cipherhexa[4][4])
{
    string right[4];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            right[j] += cipherhexa[i][j];
    for (int i = 0; i < 4; i++)
    {
        string left = decryptMixMatrix[i], products[4] = {};
        for (int j = 0; j < 4; j++)
        {
            int index = 0;
            for (int k = 0; k < 4; k++)
            {
                string bin = Hexa_to_Binary(right[j].substr(index, 2));
                char n = left[k];
                if (n == '9')
                {
                    mixCondition_Two(bin, products, k);
                    mixCondition_Two(products[k], products, k);
                    mixCondition_Two(products[k], products, k);
                    products[k] = XOR(products[k], bin);

                }
                else if (n == 'b')
                {
                    mixCondition_Two(bin, products, k);
                    mixCondition_Two(products[k], products, k);
                    products[k] = XOR(products[k], bin);
                    mixCondition_Two(products[k], products, k);
                    products[k] = XOR(products[k], bin);

                }
                else if (n == 'd')
                {
                    mixCondition_Two(bin, products, k);
                    products[k] = XOR(products[k], bin);
                    mixCondition_Two(products[k], products, k);
                    mixCondition_Two(products[k], products, k);
                    products[k] = XOR(products[k], bin);




                }
                else
                {
                    mixCondition_Two(bin, products, k);
                    products[k] = XOR(products[k], bin);
                    mixCondition_Two(products[k], products, k);
                    products[k] = XOR(products[k], bin);
                    mixCondition_Two(products[k], products, k);
                }
                index += 2;
            }

            string block = XOR(XOR(XOR(products[0], products[1]), products[2]), products[3]);
            string first = block.substr(0, 4);
            string second = block.substr(4, 4);
            cipherhexa[i][j] = {};
            cipherhexa[i][j] += Binary2Hexa(first);
            cipherhexa[i][j] += Binary2Hexa(second);

        }
    }


}

void T4_AES::mixCondition_Two(string Bin, string p[4], int k)
{
    if (Bin[0] == '1')
    {
        Bin += '0';                 // shift left
        Bin.erase(Bin.begin());
        p[k] = XOR("00011011", Bin);
    }
    else
    {
        Bin += '0';                 // shift left
        Bin.erase(Bin.begin());
        p[k] = Bin;
    }


}
void T4_AES::mixCondition_Three(string bin, string products[4], int k)
{
    string tmp = bin;
    if (bin[0] == '1')
    {
        bin += '0';                 // shift left
        bin.erase(bin.begin());
        products[k] = XOR(XOR("00011011", bin), tmp);

    }
    else
    {
        bin += '0';                 // shift left
        bin.erase(bin.begin());
        products[k] = XOR(bin, tmp);

    }
}

void T4_AES::Key_Generation(string k, string key_schedule[4][44])
{
    int id = 0, rcon_id = 0;
    for (int i = 0; i < 4; i++)					// reading the key
        for (int j = 0; j < 4; j++)
        {
            key_schedule[j][i] += toupper(k[id++]);
            key_schedule[j][i] += toupper(k[id++]);
        }
    for (int i = 4; i < 44; i++)
    {
        if (i % 4 == 0)
        {
            string sunbites[4];
            sunbites[0] = key_schedule[1][i - 1];			// Rotate
            sunbites[1] = key_schedule[2][i - 1];
            sunbites[2] = key_schedule[3][i - 1];
            sunbites[3] = key_schedule[0][i - 1];
            for (int j = 0; j < 4; j++)								// sbox
            {
                sunbites[j] = Sub_bytes(sunbites[j], 0);
                string tmp = XOR_hexa(sunbites[j], key_schedule[j][i - 4]);
                key_schedule[j][i] = XOR_hexa(tmp, rcon[j][rcon_id]);
            }
            rcon_id++;
        }
        else
            for (int j = 0; j < 4; j++)
            {
                string tmp = XOR_hexa(key_schedule[j][i - 1], key_schedule[j][i - 4]);
                key_schedule[j][i] = tmp;
            }
    }
    /*for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 44; j++)
            cout << key_schedule[i][j] << ' ';
        cout << endl;
    }*/
    return;
}

string T4_AES::Hexa_to_Binary(string s)
{
    string res;
    for (int i = 0; i < s.size(); i++)
    {
        s[i] = toupper(s[i]);
        int n = decimal_of_hex[(int)s[i]];
        char bin4[5] = { '0', '0','0','0','0' };          // itoa can't convert 15 in 4 digits for some reason 😦
        _itoa_s(n, bin4, 2);
        for (int j = 0; j < 4; j++)
            if (bin4[j] != '0' && bin4[j] != '1')
                res += "0";
        res += bin4;
    }
    return res;
}

string T4_AES::XOR(string plain, string key)
{
    string output = plain;
    for (int k = 0; k < plain.size(); k++)
        if (plain[k] == key[k])
            output[k] = '0';
        else
            output[k] = '1';
    return output;
}

string T4_AES::XOR_hexa(string a, string b)
{
    a = Hexa_to_Binary(a);
    b = Hexa_to_Binary(b);
    string bin = XOR(a, b), res;
    for (int i = 0; i < bin.size(); i += 4)
        res += Binary2Hexa(bin.substr(i, 4));
    return res;
}

string T4_AES::circular_shift(string& S, int bits, bool left)
{
    while (bits--)
    {
        if (left)
        {
            for (int i = 0; i < 2; i++)
            {
                S += S[0];
                S.erase(S.begin());
            }
        }
        else                    // right shift not needed
        {
            for (int i = 0; i < 2; i++)
            {
                S.insert(S.begin(), S[S.size() - 1]);
                S.erase(S.end() - 1);
            }
        }
    }

    return S;
}


string T4_AES::Sub_bytes(string s, bool inverse)
{
    char r = decimal_of_hex[s[0]];
    char c = decimal_of_hex[s[1]];
    if (inverse) { return InverseSbox[r][c]; }

    else { return sbox[r][c]; }
}

int T4_AES::Binary2Decimal(string S)
{
    int res = 0;
    for (int i = 0; i < S.size(); i += 8)
    {
        string tmp = S.substr(i, 8);
        res = (bitset<8>(tmp).to_ullong());
    }
    return res;
}

char T4_AES::Binary2Hexa(string s)
{
    int n = Binary2Decimal(s);
    return hex_of_decimal[n];
}

void T4_AES::AddRoundKey(string mixed[4][4], int keyIndex, string key[4][44])
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            mixed[j][i] = XOR_hexa(mixed[j][i], key[j][keyIndex + i]);
}
