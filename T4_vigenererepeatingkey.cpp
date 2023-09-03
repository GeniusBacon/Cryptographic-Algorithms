#include <iostream>
#include "T4_VigenereRepeatingKey.h"
#include "T4_Railfence.h"
#include <string>
using namespace std;

void T4_VigenereRepeatingKey::createVigenereTable()
{
    for (int i = 0; i < 26; i++)
    {
        for (int j= 0; j < 26; j++)
        {
            VigenereTable[i][j] = (j + i) % 26;
            //cout << VigenereTable[i][j] << " ";
        }
        //cout << endl;
    }
}
string T4_VigenereRepeatingKey::Encrypt_repeating(string PlainText, string key)
{    // key > hello
    // PT  > computerscience
    for (int i = 0; i < PlainText.size(); i++)
    {
        PlainText[i] = tolower(PlainText[i]);
    }


    T4_Railfence R;
    PlainText = R.Trim(PlainText);

    string RepeatingKey = PlainText;
    string Cipher = PlainText;
    int IndexP = 0;
    for (int i = 0; i < PlainText.size(); i++)
    {
        if (i < key.size())
        {

            RepeatingKey[i] = key[i]; //hello 5
        }
        else
        {
            if ((IndexP+1) == key.size())
            {
                RepeatingKey[i] = key[IndexP];
                IndexP = 0;
            }
            else
            {
            RepeatingKey[i] = key[IndexP];  //hellohell
            IndexP++; //0 1  2 3 4
            }
        }
    }


    for (int i = 0; i < PlainText.size(); i++)
    {
        Cipher[i] =(char) VigenereTable[(RepeatingKey[i] - 'a')][(PlainText[i] - 'a')]+ 'a';
    }


    for (int i = 0; i < Cipher.size(); i++)
    {
        Cipher[i] = toupper(Cipher[i]);
    }
    return Cipher;



}

string T4_VigenereRepeatingKey::Decrypt_repeating(string cipher, string key)
{

    T4_Railfence R;
    for (int i = 0; i < cipher.size(); i++)
    {
        cipher[i] = tolower(cipher[i]);
    }
    cipher = R.Trim(cipher);

    string RepeatingKey = cipher;
    string Plain = cipher;
    int IndexP = 0;
    for (int i = 0; i < cipher.size(); i++)
    {
        if (i < key.size())
        {

            RepeatingKey[i] = key[i]; //hello 5
        }
        else
        {
            if ((IndexP + 1) == key.size())
            {
                RepeatingKey[i] = key[IndexP]; //hello
                IndexP = 0;
            }
            else
            {
                RepeatingKey[i] = key[IndexP];  //hellohell
                IndexP++; //0 1  2 3 4
            }
        }
    }



    for (int i = 0; i < cipher.size(); i++)//8
    {
        for (int j = 0; j < 26; j++)
        {
            int x = (int)(RepeatingKey[i] - 'a');
            if ((VigenereTable[j][x]) == (int)cipher[i]-'a')
            {
                Plain[i] = (char)(j + 'a');
            }

        }
    }

    return Plain;

}


string T4_VigenereRepeatingKey::Analyse_repeating(string PlainText, string cipher)
{
    for (int i = 0; i < cipher.size(); i++)
    {
        cipher[i] = tolower(cipher[i]);
    }
    for (int i = 0; i < PlainText.size(); i++)
    {
        PlainText[i] = tolower(PlainText[i]);
    }

    T4_Railfence R;
    PlainText = R.Trim(PlainText);
    cipher = R.Trim(cipher);

    string Key = cipher;



    for (int i = 0; i < cipher.size(); i++)//8
    {
        for (int j = 0; j < 26; j++)
        {
            int x = (int)(PlainText[i] - 'a');
            if ((VigenereTable[j][x]) == (int)cipher[i] - 'a')
            {
                Key[i] = (char)(j + 'a');
            }

        }
    }

    return Key;
}

