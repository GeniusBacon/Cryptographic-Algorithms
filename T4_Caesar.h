#ifndef T4_CAESAR_H
#define T4_CAESAR_H


#include <string>

using namespace std;

class T4_Caesar
{
    public:

        string Encrypt(string, int);
        string Decrypt(string, int);
        int Analyze(string, string);
        long long mod(long long, long long);

};

#endif // T4_CAESAR_H
