#include <iostream>
#include "funcs.h"
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"

int main(){
  std::cout << "test_ascii(Cat :3 Dog)" << "\n" << test_ascii("Cat :3 Dog") << "\n";
  std::cout << "encryptCaesar(Way to Go!, 5)" << "\n" << encryptCaesar("Way to Go!", 5) << "\n";
  std::cout << "encryptVigenere(Hello, World!, cake)" << "\n" << encryptVigenere("Hello, World!", "cake") << "\n";
  std::cout << "decryptCaesar(Bfd yt Lt!, 5)" << "\n" << decryptCaesar("Bfd yt Lt!", 5) << "\n";
  return 0;
}
