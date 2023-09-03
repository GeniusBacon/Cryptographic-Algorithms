#ifndef T4_RSA_H
#define T4_RSA_H


class T4_RSA
{
public:
    int rsa_encrypt(int, int, int);
    int rsa_keysetup(int, int);
    int rsa_decrypt(int, int, int);
    int modular_multiplicative_inverse(int, int);
    int modular_power(int, int, int);
    bool isPrime(int);
};



#endif // T4_RSA_H
