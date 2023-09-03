#include "T4_VigenereAutoKey.h"
#include "T4_Railfence.h"
#include <string>
#include <math.h>
#include <iostream>

using namespace std;


string T4_VigenereAutoKey::Encrypt(string PlainText, string AutoKey)
{
    for (int i = 0; i < PlainText.size(); i++)
    {
        PlainText[i] = tolower(PlainText[i]);
    }


    T4_Railfence R;
    PlainText = R.Trim(PlainText);

    string Key=PlainText;
    string Cipher=PlainText;
    int IndexP=0;
    for (int i = 0; i < PlainText.size(); i++)
    {
        if (i < AutoKey.size())
        {

            Key[i] = AutoKey[i];
        }
        else
        {
            Key[i] = PlainText[IndexP];
            IndexP++;
        }

    }

    for (int i = 0; i < PlainText.size(); i++)
    {
        int x = (((int)(Key[i]-'a' ) + (int)(PlainText[i]-'a'))% 26);
        Cipher[i] = (char)('a' + x);
    }

    for (int i = 0; i < Cipher.size(); i++)
    {
        Cipher[i] = toupper(Cipher[i]);
    }

    return Cipher;
}

string T4_VigenereAutoKey::Decrypt(string Cipher, string AutoKey)
{


    for (int i = 0; i < Cipher.size(); i++)
    {
        Cipher[i] = tolower(Cipher[i]);
    }
    string Key = Cipher;
    string Plain = Cipher;
    int IndexP = 0;
  /////////////////////////////////////////////////////// MODIFICATION REST OF KEY
    string Rest="";
    int counter = (Cipher.size() - AutoKey.size());
    for (int z = 0; z <counter ; z++)
    {
        int a = (((int)(Cipher[z] - 'a') - (int)(AutoKey[z] - 'a')) % 26);
        int y = (a % 26 + 26) % 26;
        Rest+= (char)('a' + y);
    }
///////////////////////////////////////////////////////

    for (int i = 0; i < Cipher.size(); i++)
    {             //5
        if (i < AutoKey.size())
        {

            Key[i] = AutoKey[i];
        }
        else
        {
            Key[i] = Rest[IndexP];
            IndexP++;
        }

    }
  /////////////////////////////////////////////////////////MODIFICATION PADDING
    T4_Railfence R;
    Cipher = R.Trim(Cipher);
    for (int i = 0; i < Cipher.size(); i++)
    {
        int x = (((int)(Cipher[i] - 'a') - (int)(Key[i] - 'a') )%26);
        int z = (x % 26 + 26) % 26;
        Plain[i] = (char)('a' + z);
    }

    return Plain;
}


string T4_VigenereAutoKey::Analyse(string PlainText, string Cipher)
{
    T4_Railfence R;

    for (int i = 0; i < Cipher.size(); i++)
    {
        Cipher[i] = tolower(Cipher[i]);
    }

    for (int i = 0; i < PlainText.size(); i++)
    {
        PlainText[i] = tolower(PlainText[i]);
    }
    PlainText = R.Trim(PlainText);
    Cipher = R.Trim(Cipher);
    string Key= PlainText;
    for (int i = 0; i < PlainText.size(); i++)
    {
        int x = (((int)(Cipher[i] - 'a') - (int)(PlainText[i] - 'a')));
        int z = (x % 26+26)%26;

        Key[i] = (char)('a' + z);
    }
    return Key;
}




