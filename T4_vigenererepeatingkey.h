#ifndef T4_VIGENEREREPEATINGKEY_H
#define T4_VIGENEREREPEATINGKEY_H

#include <iostream>
#include <string>
using namespace std;

class T4_VigenereRepeatingKey
{

public:
    int VigenereTable[26][26];
    void createVigenereTable();
    string  Encrypt_repeating(string, string);
    string  Decrypt_repeating(string, string);
    string  Analyse_repeating(string, string);
};

#endif // T4_VIGENEREREPEATINGKEY_H
