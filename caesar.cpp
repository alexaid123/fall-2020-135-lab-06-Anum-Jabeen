#include <iostream>
#include "caesar.h"

char shiftChar(char c, int rshift){
   int num; // Writing comments for the dev branch 
   if(isupper(c)){ // More comments 
   // Added a space 
      num = ((int)c - 65 + rshift) % 26 + 65; 
      if(num<65){
         return char(26+num); // Second Commenting 
      }
      return char(num);
   }
   else if(islower(c)){
      num = ((int)c - 96 + rshift) % 26 + 96;
      if(num < 97){
        return char(26+num); // Comments 
      } 
      return char(num);
   }
   return c;
   // Added another space
}

std::string encryptCaesar(std::string plaintext, int rshift){
   std::string code;
   for(int i = 0; i < plaintext.length(); i++){
       code+= shiftChar(plaintext[i], rshift);
   }
   return code;
}
