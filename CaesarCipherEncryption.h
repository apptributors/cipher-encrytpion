#ifndef CAESAR_CIPHER_ENCRYPTION_H
#define CAESAR_CIPHER_ENCRYPTION_H
#include <cstring>

#include "CipherEncryption.h"

class CaesarCipherEncryption : public CipherEncryption
{
  protected:
    char *getEncryptionKey() const
    {
        return "x003";
    }

  public:
    char *encrypt(char *);
    char *decrypt(char *);
};

char *CaesarCipherEncryption::encrypt(char *message)
{
    const int SIZE = strlen(message);
    char *output = new char[SIZE];
    while (message)
    {
        *output = *message + 5;
        message++;
        output++;
    }
    *output = '\0';
    // To add encryption key to encrypted key and return pointer to it
    return strcat(output - SIZE, getEncryptionKey());
}

char *CaesarCipherEncryption::decrypt(char *cipher)
{
    const int SIZE = strlen(cipher);
    char *output = new char[SIZE];
    while (cipher)
    {
        *output = *cipher - 5;
        cipher++;
        output++;
    }
    *output = '\0';
    // To reposition pointer to the starting point
    return output - SIZE;
}

#endif