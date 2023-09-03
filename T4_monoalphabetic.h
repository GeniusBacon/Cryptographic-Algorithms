#ifndef T4_MONOALPHABETIC_H
#define T4_MONOALPHABETIC_H

#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;
class T4_monoalphabetic
{
public:
    string Encrypt_Monoalphabetic(string p, string k);
    string Decrypt_Monoalphabetic(string c, string k);
    bool pair_letters_sort(pair<char, int> a, pair<char, int> b);
    string AnalyzeUsingCharFrequency(string c);
};

#endif // T4_MONOALPHABETIC_H
