#include <iostream>
#include "caesar.h"

char shiftChar(char c, int rshift){
   char upperC, lowerC;
   if(isupper(c)){
      upperC = (c + rshift - 65) % 26 + 65; 
      return upperC;
   }
   else if(islower(c)){
      lowerC = (c + rshift - 97) % 26 + 97;
      return lowerC; 
   }
   else{
      return c;
   }
}

std::string encryptCaesar(std::string plaintext, int rshift){
   std::string code;
   for(int i = 0; i < plaintext.length(); i++){
       code+= shiftChar(plaintext[i], rshift);
   }
   return code;
}
