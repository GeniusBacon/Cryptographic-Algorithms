#ifndef T4_HILLCIPHER_H
#define T4_HILLCIPHER_H


#include <vector>

using namespace std;


class T4_HillCipher
{
public:
    vector<int> Encrypt(vector<int>, vector<int>);
    int get_matrix_determinent(vector<int> m);
    vector<int> get_matrix_inverse(vector<int> m);
    vector<int> Decrypt(vector<int>, vector<int>);
    vector<int> get_matrix_adjucate(vector<int> m);
    int modular_multiplicative_inverse(int n, int m);
    vector<int> get_matrix_transpose(vector<int> m);
    vector<int> Analyse_key2(vector<int>, vector<int>);
    vector<int> Analyse_key3(vector<int>, vector<int>);
    vector<int> square_matrix_multiplication(vector<int>, vector<int>);
};

#endif // T4_HILLCIPHER_H
