#include <iostream>
#include "funcs.h"

void test_ascii(std::string words){
   for(int i = 0; i < words.length(); i++){
       std::cout << words[i] << " " << (int)words[i] << std::endl;
  }
}

