#include <iostream>
#include "caesar.h"

char shiftChar(char c, int rshift){
   int num;
   if(isupper(c)){
      num = ((int)c - 65 + rshift) % 26 + 65; 
      if(num<65){
         return char(26+num);
      }
      return char(num);
   }
   else if(islower(c)){
      num = ((int)c - 96 + rshift) % 26 + 96;
      if(num < 97){
        return char(26+num); 
      } 
      return char(num);
   }
   return c;
}

std::string encryptCaesar(std::string plaintext, int rshift){
   std::string code;
   for(int i = 0; i < plaintext.length(); i++){
       code+= shiftChar(plaintext[i], rshift);
   }
   return code;
}
