#ifndef T4_VIGENEREAUTOKEY_H
#define T4_VIGENEREAUTOKEY_H

#include <iostream>
#include <string>
using namespace std;

class T4_VigenereAutoKey
{

public:
    string  Encrypt(string, string);
    string  Decrypt(string, string);
    string  Analyse(string, string);
};

#endif // T4_VIGENEREAUTOKEY_H
