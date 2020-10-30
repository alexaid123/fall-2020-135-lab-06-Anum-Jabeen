

main: main.o funcs.o caesar.o vigenere.o decrypt.o decode.o
	g++ -o main main.o funcs.o caesar.o vigenere.o decrypt.o decode.o

tests: tests.o caesar.o vigenere.o decrypt.o
	g++ -o tests tests.o caesar.o vigenere.o decrypt.o


funcs.o: funcs.cpp funcs.h

caesar.o: caesar.cpp caesar.h

vigenere.o: vigenere.cpp vigenere.h

decrypt.o: decrypt.cpp decrypt.h

main.o: main.cpp funcs.h caesar.h vigenere.h decrypt.h decode.h

decode.o: decode.cpp decode.h decrypt.h 

tests.o: tests.cpp  doctest.h caesar.h vigenere.h decrypt.h

clean:
	rm -f main.o tests.o funcs.o caesar.o vigenere.o decrypt.o decode.o

help:
	@echo  make main : make executable named main
	@echo make tests : make test suite named tests

