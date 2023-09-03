#ifndef T4_PLAYFAIR_H
#define T4_PLAYFAIR_H

#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

class T4_playfair
{
public:

    string Encrypt_playfair(string p, string key);
    string Decrypt_playfair(string c, string key);


};

#endif // T4_PLAYFAIR_H
