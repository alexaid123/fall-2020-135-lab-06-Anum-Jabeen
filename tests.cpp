#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"
#include "caesar.h"

TEST_CASE("encryptCaesar"){
	CHECK(encryptCaesar("Way to Go!", 5) == "Bfd yt Lt!");
        CHECK(encryptCaesar("Bfd yt Lt!", -5) == "Way to Go!");
        CHECK(encryptCaesar("#!6873804", 21) == "#!6873804");
        CHECK(encryptCaesar("HELLO!", 0) == "HELLO!");
}
