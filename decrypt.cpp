#include <iostream>
#include "caesar.h"
#include "decrypt.h"

std::string decryptCaesar(std::string ciphertext, int rshift){
     return encryptCaesar(ciphertext,-rshift);
}

std::string decryptVigenere(std::string ciphertext, std::string keyword){
    std::string code;
    int shift;
    int count = 0;
    for(int i = 0; i<ciphertext.length(); i++){
        if(isalpha(ciphertext[i])){
          if(islower(keyword[count])){
            shift = ((int)keyword[count])-'a';
            code+= shiftChar(ciphertext[i],-shift);
            count+=1;
            if(count == keyword.length()){
               count = 0;
            }
          }
          else if(isupper(keyword[count])){
            shift = ((int)keyword[count])-'A';
            code+= shiftChar(ciphertext[i],-shift);
            count+=1;
            if(count == keyword.length()){
               count = 0;
            }
          }
        }else{
            code+=ciphertext[i];
        }
    } 
    return code;
}
