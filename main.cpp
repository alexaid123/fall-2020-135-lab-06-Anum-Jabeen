#include <iostream>
#include "funcs.h"
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"
#include "decode.h"

int main(){
  std::cout << "test_ascii(Cat :3 Dog)" << "\n";
  test_ascii("Cat :3 Dog");
  std::cout << "encryptCaesar(Way to Go!, 5)" << "\n" << encryptCaesar("Way to Go!", 5) << "\n";
  std::cout << "encryptVigenere(Hello, World!, cake)" << "\n" << encryptVigenere("Hello, World!", "cake") << "\n";
  std::cout << "decryptCaesar(Rovvy, Gybvn!, 10)" << "\n" << decryptCaesar("Rovvy, Gybvn!", 10) << "\n";
  std::cout << "decryptVigenere(Jevpq, Wyvnd!, cake)" << "\n" << decryptVigenere("Jevpq, Wyvnd!", "cake") << "\n\n";
  std::cout << "decode(encryptCaesar(Way to Go!, 5))" << "\n" << decode(encryptCaesar("Way to Go!", 5)) << "\n\n";
  return 0;
}
