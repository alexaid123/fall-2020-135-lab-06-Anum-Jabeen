#include <iostream>
#include "vigenere.h"
#include "caesar.h"

std::string encryptVigenere(std::string plaintext, std::string keyword){
    std::string code;
    int shift;
    int count = 0;
    for(int i = 0; i<plaintext.length(); i++){
        if(isalpha(plaintext[i])){
          if(islower(keyword[count])){
            shift = ((int)keyword[count])-'a';
            code+= shiftChar(plaintext[i],shift);
            count+=1;
            if(count == keyword.length()){
               count = 0;
            }
          }
          else if(isupper(keyword[count])){
            shift = ((int)keyword[count])-'A';
            code+= shiftChar(plaintext[i],shift);
            count+=1;
            if(count == keyword.length()){
               count = 0;
            }
          }
        }else{
            code+=plaintext[i];
        }
    } 
    return code;
}
