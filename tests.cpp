#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"
#include "caesar.h"
#include "vigenere.h'
#include "decrypt.h"

TEST_CASE("shiftChar"){
     CHECK(shiftChar('a',4) == 'e');
     CHECK(shiftChar('C',3) == 'F');
     CHECK(shiftChar('j',0) == 'j');
     CHECK(shiftChar('K',-6) == 'E');
}

TEST_CASE("encryptCaesar"){
     CHECK(encryptCaesar("Way to Go!", 5) == "Bfd yt Lt!");
     CHECK(encryptCaesar("Bfd yt Lt!", -5) == "Way to Go!");
     CHECK(encryptCaesar("#!6873804", 21) == "#!6873804");
     CHECK(encryptCaesar("HELLO!", 0) == "HELLO!");
}

TEST_CASE("encryptVigenere"){
     CHECK(encryptVigenere("Hello, World!", "cake")=="Jevpq, Wyvnd!");
     CHECK(encryptVigenere("ATTACKATDAWN", "LEMON")=="LXFOPVEFRNHR");
     CHECK(encryptVigenere("Hello, 60122&^%,", "cake")=="Jevpq, 60122&^%,");
     CHECK(encryptVigenere("97864@#&*!!!!)56378", "sameinputoutput")=="97864@#&*!!!!)56378");
     CHECK(encryptVigenere(" ", "EmPtY")==" ");
}

TEST_CASE("decryptCaesar"){
     CHECK(decryptCaesar("Bfd yt Lt!",5)=="Way to Go!");
     CHECK(decryptCaesar("Way to Go!",-5)=="Bfd yt Lt!");
     CHECK(decryptCaesar("97864@#&*!!!!)56378",87)=="97864@#&*!!!!)56378");
     CHECK(decryptCaesar("HELLO!",0)=="HELLO!");
}

TEST_CASE("decryptVigenere"){
     CHECK(decryptVigenere("Jevpq, Wyvnd!", "cake")=="Hello, World!");
     CHECK(decryptVigenere("LXFOPVEFRNHR", "LEMON")=="ATTACKATDAWN");
     CHECK(decryptVigenere("Jevpq, 60122&^%,", "cake")=="Hello, 60122&^%,");
     CHECK(decryptVigenere("97864@#&*!!!!)56378", "hdjoak")=="97864@#&*!!!!)56378");
     CHECK(decryptVigenere(" ", "EmPtY")==" ");
}
