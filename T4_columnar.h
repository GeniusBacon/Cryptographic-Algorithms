#ifndef T4_COLUMNAR_H
#define T4_COLUMNAR_H

#include <vector>
#include <iostream>
#include <list>

using namespace std;

class T4_Columnar
{

public:

    vector<int> keyVector;
    string plaintext;
    string key;
    string Encrypt(string, vector<int>);
    string Decrypt(string, vector<int>);
    list<int> Analyze(string, string);
    void insertKey();
    int get(list<int>, int);
};


#endif // T4_COLUMNAR_H
