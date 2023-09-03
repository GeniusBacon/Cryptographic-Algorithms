#include "T4_Columnar.h"
#include"T4_Railfence.h"
#include <string.h>
#include <iostream>
using namespace std;



void T4_Columnar::insertKey()
{

    cin >> key;
    for (int i = 0; i < key.size(); i++)
    {
        keyVector.push_back((int)(key[i] - 48));
    }


}
//string T4_Columnar::Encrypt(string plaintext, vector<int>)
string T4_Columnar::Encrypt(string plaintext, vector<int> key)

{   // computerscience
    // 4 3 1 2 5
    T4_Railfence R;
    plaintext = R.Trim(plaintext);
    int counter = 0;
    int Col = key.size(); // 5
    int Row = ceil(plaintext.size() / (float)Col); //3
    vector <vector <char>> Cipher;
    string CipherString = plaintext;
    for (int i = 0; i < Row; i++)
    {
        vector<char> pushVector;

        for (int j = 0; j < Col; j++)
        {
            if (plaintext.size() <= counter)
            {
                pushVector.push_back('x');
                continue;
            }
            pushVector.push_back(plaintext[counter]);
            counter++;
        }
        Cipher.push_back(pushVector);

    }


    int CipherCounter = 1;
    int CurrentColumn = 0;
    int stringCnt = 0;
    for (int i = 0; i < Col; i++)//5
    {    //0

        // 1 3 4 2 5
        for (int x = 0; x < key.size(); x++)//5
        {
            if (key[x] == CipherCounter)
            {
                CurrentColumn = x;
                CipherCounter++;
                break;
            }
        }
        for (int j = 0; j < Row; j++)//3
        {

            if (plaintext.size() <= stringCnt)
            {
                CipherString.append(1, Cipher[j][CurrentColumn]);


            }
            else
            {
                CipherString[stringCnt] = Cipher[j][CurrentColumn];
            }
            stringCnt++;

        }
    }

    /*for (int i = 0; i < CipherString.size(); i++)
    {
        CipherString[i] = toupper(CipherString[i]);
    }*/

    return CipherString;

}


string T4_Columnar::Decrypt(string Cipher, vector<int> key /*modification*/)
{   // computerscience
    // 4 3 1 2 5
    T4_Railfence R;
    Cipher = R.Trim(Cipher);
    int counter = 0;
    int Row = key.size(); //5
    int Col = ceil(Cipher.size() / (float)Row); // 3
    vector <vector <char>> Plain;
    string PlainString = Cipher;


    for (int i = 0; i < Row; i++)//5
    {
        vector<char> pushVector;

        for (int j = 0; j < Col; j++)//3
        {

            pushVector.push_back(Cipher[((key[counter] - 1) * Col) + j]);/*modification*/

        }
        Plain.push_back(pushVector);
        counter++;

    }


    int CipherCounter = 1;
    int CurrentColumn = 0;
    int stringCnt = 0;
    for (int i = 0; i < Col; i++)//3
    {

        for (int j = 0; j < Row; j++)//5
        {

            PlainString[stringCnt] = Plain[j][i];
            stringCnt++;

        }
    }

    return PlainString;

}

list <int> T4_Columnar::Analyze(string plaintext, string ciphertext)
{

    T4_Railfence R;
    for (int i = 0; i < plaintext.size(); i++)
    {
        plaintext[i] = tolower(plaintext[i]);
    }
    for (int i = 0; i < ciphertext.size(); i++)
    {
        ciphertext[i] = tolower(ciphertext[i]);
    }
    plaintext = R.Trim(plaintext);
    ciphertext = R.Trim(ciphertext);

    int Flag = 0;
    int Colcounter = 0;
    char FirstLetter;
    char SecLetter;
    list <int> key;
    list <int> ActualKey;
    int tempKey[9000];
    FirstLetter = ciphertext[0];
    SecLetter = ciphertext[1];
    for (int i = 0; i < plaintext.size(); i++)
    {
        if (FirstLetter == plaintext[i])
        {
            for (int j = i + 1; j < plaintext.size(); j++)
            {
                if (SecLetter == plaintext[j])
                {
                    Flag = 1;
                    Colcounter++;
                    break;
                }
                Colcounter++;
            }
            if (Flag)
            {
                break;
            }
        }
    }

    int counter = 0;
    int Col = Colcounter; // 5
    int Row = ceil(plaintext.size() / (float)Col); //3
    vector <vector <char>> Cipher;
    string CipherString = plaintext;
    for (int i = 0; i < Row; i++)
    {
        vector<char> pushVector;

        for (int j = 0; j < Col; j++)
        {
            if (plaintext.size() <= counter)
            {
                pushVector.push_back('x');
                continue;
            }
            pushVector.push_back(plaintext[counter]);
            counter++;
        }
        Cipher.push_back(pushVector);

    }

    int Pos = 0;

    string compare;
    for (int i = 0; i < Colcounter; i++)
    {
        int flag = 0;
        compare = ciphertext.substr(Pos, Row);


        for (int j = 0; j < Colcounter; j++)
        {
            string ciphersubstr;
            for (int k = 0; k < Row; k++)
            {
                ciphersubstr.append(1, Cipher[k][j]);
            }
            if (compare == ciphersubstr)
            {
                key.push_back((j + 1));
                flag = 1;

            }

            if (flag == 1)
            {
                break;
            }
        }
        Pos += Row;
    }



    for (int i = 0; i < Colcounter; i++)
    {
        int temp = get(key, i);
        tempKey[temp - 1] = i + 1;

    }
    for (int i = 0; i < Colcounter; i++)
    {
        ActualKey.push_back(tempKey[i]);
    }
    return ActualKey;
}

int T4_Columnar::get(list<int> _list, int _i) {
    list<int>::iterator it = _list.begin();
    for (int i = 0; i < _i; i++) {
        ++it;
    }
    return *it;
}
