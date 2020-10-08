#include <iostream>
#include "caesar.h"
#include "decrypt.h"

std::string decryptCaesar(std::ciphertext, int rshift){
     std::string decryption;    
     decryption = encryptCaesar(ciphertext,-rshift);
     return decryption;
}
