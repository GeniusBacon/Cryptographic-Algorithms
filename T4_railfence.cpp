#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "T4_Railfence.h"
using namespace std;


string T4_Railfence::encrypt_railfence(string plain, int key)
{
    for (int i = 0; i < plain.size(); i++)
    {
        plain[i] = tolower(plain[i]);
    }

    plain = Trim(plain);



    string plaintext = plain;
    int depth = key;
    vector < vector<char>> cipher = {};

    string c = plaintext;
    int counter = 0;
    int counter2 = 0;
    int spaceCnt = 0;


    for (int i = 0; i < ceil(plaintext.size() / (float)depth); i++)//3
    {
        vector<char> depthC;
        for (int j = 0; j < depth; j++)//2
        {
            depthC.push_back(plaintext[counter]);
            counter++;
        }

        cipher.push_back(depthC);
    }
    for (int i = 0; i < depth; i++) // 2
    {

        for (int j = 0; j < ceil(plaintext.size() / (float)depth); j++) //3
        {
            c[counter2] = cipher[j][i];
            counter2++;
        }

    }
    for (int i = 0; i < c.size(); i++)
    {
        c[i] = toupper(c[i]);
    }
    return c;
}

string T4_Railfence::decrypt_railfence(string cipher, int key)
{
    for (int i = 0; i < cipher.size(); i++)
    {
        cipher[i] = tolower(cipher[i]);
    }
    cipher = Trim(cipher);

    string cipher1 = cipher;
    int depth = key;
    vector < vector<char>> plain = {};

    string p = cipher1;
    int counter = 0;
    int counter2 = 0;

    for (int i = 0; i < depth; i++)//2
    {

        vector<char> depthP;

        for (int j = 0; j < ceil(cipher1.size() / (float)depth); j++)//3
        {
            /*if (cipher1[i] < 'a' || cipher1[i] > 'z')
            {
                continue;
            }
            else*/
            depthP.push_back(cipher1[counter]);
            counter++;


        }

        plain.push_back(depthP);

    }

    for (int i = 0; i < ceil(cipher1.size() / (float)depth); i++) // 3
    {

        for (int j = 0; j < depth; j++) //2
        {

            p[counter2] = plain[j][i];
            counter2++;

        }
    }
    return p;
}

int T4_Railfence::analyze_railfence(string plain, string cipher)
{
    for (int i = 0; i < cipher.size(); i++)
    {
        cipher[i] = tolower(cipher[i]);
    }
    for (int j = 0; j < plain.size(); j++)
    {
        plain[j] = tolower(plain[j]);

    }
    plain = Trim(plain);
    cipher = Trim(cipher);

    int key = 0;
    for (int i = 1; i < cipher.size(); i++)
    {
        string cipherCompare = encrypt_railfence(plain, i);
        for (int j = 0; j < cipherCompare.size(); j++)
        {
            cipherCompare[j] = tolower(cipherCompare[j]);

        }
        if (cipherCompare != cipher)
        {
            continue;
        }
        else if (cipherCompare == cipher)
        {
            key = i;
            break;

        }
    }


    return key;
}

string T4_Railfence::Trim(string P)
{
    string Trim;
    for (int i = 0; i < P.size(); i++)
    {
        if (P[i] <= 'z' && P[i] >= 'a')
        {
            Trim.append(1, P[i]);
        }
    }
    return Trim;
}
