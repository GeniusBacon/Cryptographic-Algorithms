#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <utility>
#include <algorithm>
#include <vector>
#include "T4_monoalphabetic.h"

using namespace std;

string T4_monoalphabetic::Encrypt_Monoalphabetic(string p, string k)
{
    string c = p;
    map <char, char> keymap;
    for (int i = 0; i < 26; i++)		// key size should be 26 letters
        keymap['a' + i] = toupper(k[i]);

    for (int i = 0; i < p.size(); i++)
    {
        p[i] = tolower(p[i]);
        if (p[i] < 'a' || p[i] > 'z')
        {
            c[i] = p[i];
            continue;
        }
        c[i] = keymap[p[i]];
    }
    return c;
}

string T4_monoalphabetic::Decrypt_Monoalphabetic(string c, string k)
{
    string p = c;
    map <char, char> keymap;
    for (int i = 0; i < 26; i++)
        keymap[(k[i])] = 'a' + i;
    for (int i = 0; i < c.size(); i++)
    {
        c[i] = tolower(c[i]);
        if (c[i] < 'a' || c[i] > 'z')
        {
            p[i] = c[i];
            continue;
        }
        p[i] = keymap[c[i]];
    }
    return p;
}

bool pair_letters_sort(pair<char, int> a, pair<char, int> b)
{
    if (a.second < b.second || (a.second == b.second && a.first < b.first))
        return true;
    return false;
}

string T4_monoalphabetic::AnalyzeUsingCharFrequency(string c)
{

    pair <char, float> LettersFreq[26] = { make_pair('e',12.702) ,make_pair('t',9.056) ,make_pair('a',8.167) ,make_pair('o',7.507) ,make_pair('i',6.966) ,make_pair('n',6.749) ,make_pair('s',6.327) ,make_pair('h',6.094) ,make_pair('r',5.987) ,make_pair('d',4.253),
    make_pair('l',4.025) ,make_pair('c',2.782) ,make_pair('u' ,2.758) ,make_pair('m',2.406) ,make_pair('w',2.360) ,make_pair('f',2.228) ,make_pair('g',2.015) ,make_pair('y',1.974) ,make_pair('p',1.929) ,make_pair('b',1.492) ,make_pair('v',0.978) ,make_pair('k',0.772) ,make_pair('j',0.153)
    ,make_pair('x',0.150) ,make_pair('q',0.095) ,make_pair('z',0.074) };

    pair <string, float> BigramsFreq[20] = { make_pair("th", 3.8825) , make_pair("he", 3.6813) , make_pair("im",2.2838) , make_pair("er", 2.178) , make_pair("an", 2.1404) , make_pair("re", 1.7493) , make_pair("nd", 1.5719) , make_pair("on", 1.4182) , make_pair("en", 1.3832) , make_pair("at", 1.3355) , make_pair("ou", 1.2854) , make_pair("ed", 1.2757) , make_pair("ha", 1.2747) , make_pair("to", 1.1696)
        , make_pair("or", 1.151) , make_pair("it", 1.1348) , make_pair("is", 1.1098) , make_pair("hi", 1.092302) , make_pair("es", 1.092301)  , make_pair("ng", 1.0533) };

    pair <char, float> CipherLetters[26];

    pair <char, char> CipherToLetterMap[26];
    for (int i = 0; i < 26; i++)
    {
        CipherLetters[i].first = (char)(i + 'a');
        CipherLetters[i].second = 0;
    }
    for (int i = 0; i < c.size(); i++)
    {
        c[i] = tolower(c[i]);
        if (c[i] < 'a' || c[i] > 'z')
            continue;
        CipherLetters[c[i] - 'a'].second++;
    }

    for (int i = 0; i < 26; i++)
    {
        CipherLetters[i].second = ((CipherLetters[i].second / (c.size())) * 100);
    }

    vector < pair<string, float > > digrams  ;
    map<string, int> digramsFrequency;

    for (int i = 0; i < c.size() - 1; i++)
    {
        string tmp = c.substr(i, 2);
        digramsFrequency[tmp]++;
    }
    map<string, int>::iterator i;
    for (i = digramsFrequency.begin(); i != digramsFrequency.end(); i++)
    {
        if (i->second > 1)
        {
            digrams.push_back(make_pair(i->first, ((i->second / (c.size() - 1) ) *100)));
        }
    }



    /*for (int i = 0; i < 26; i++)
        cout << CipherLetters[i].first << ' '<< CipherLetters[i].second<<endl;*/

    /*int Reserved[26] = { 0 };
    for (int i = 0; i < 26; i++)
    {
        float temp=10000;

        int flag = 0;

        for (int j = 0; j < 26; j++)
        {

            if (j == 0 && Reserved[j] == 0) {

                 temp = abs(CipherLetters[i].second-LettersFreq[j].second);
                 CipherToLetterMap[i].first = LettersFreq[j].first;
                 CipherToLetterMap[i].second = CipherLetters[i].first;
                 cout << temp << " " << "Letter:" << CipherLetters[i].first << " " << "Cipher:" << LettersFreq[j].first << "" << endl;
                 flag = j;
                continue;
            }
            if ((abs(CipherLetters[i].second - LettersFreq[j].second)) < temp)
            {
                if (Reserved[j] == 0)
                {

                    {

                        temp = (abs(CipherLetters[i].second - LettersFreq[j].second));
                        cout << temp << " " << "Letter:" << CipherLetters[i].first << " " << "Cipher:" << LettersFreq[j].first << "" << endl;
                        CipherToLetterMap[i].first = LettersFreq[j].first;
                        CipherToLetterMap[i].second = CipherLetters[i].first;
                        flag = j;

                    }
                }
            }
        }
        Reserved[flag] = 1;
        cout << Reserved[flag] <<endl;

    }*/

    string plain = c;
    for (int i = 0; i < c.size(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (c[i] == CipherToLetterMap[j].second)
            {
                plain[i] = CipherToLetterMap[j].first;
            }
        }
    }
    return plain;
}

