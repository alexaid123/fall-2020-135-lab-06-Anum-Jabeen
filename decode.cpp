#include <iostream>
#include <cmath>
#include <vector>
#include "decode.h"
#include "decrypt.h"

std::string decode(std::string encryptedStr){
        double real_Frequencies[26] = {0.082, 0.015, 0.028, 0.043, 0.13, 0.022, 0.02, 0.061, 0.07, 0.0015, 0.0077, 0.04, 0.024, 0.067, 0.075, 0.019, 0.00095, 0.06, 0.063, 0.091, 0.028, 0.0098, 0.024, 0.0015, 0.02, 0.00074};
        char alphabet [26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        double sentence[26]; //storing frequencies of encrypted sentence here
        double distance[26];
        std::string encryptedStr2;

        //adding the frequency to vector: sentence using above function charfrequencyEncryption
        for(int i=0;i<26;i++){
                encryptedStr2 = decryptCaesar(encryptedStr, i);

                for(int j=0; j<26; j++){
                        sentence[j]=charfrequencyEncryption(encryptedStr2, alphabet[j]);
                }
                distance[i] = distanceEqn(real_Frequencies,sentence);
        }

        int shift = num_shift(distance);

        return decryptCaesar(encryptedStr, shift);

}


//charFrequency is the number of times a letter appears divided by the total number of letters: for the encrypted sentence
double charfrequencyEncryption(std::string encryptedStr, char letter){
	int count = 0;
	int length = 0;
	for(int i=0; i<encryptedStr.length(); i++){
		if(encryptedStr[i]==letter){
			count++;
                }
		if(isalpha(encryptedStr[i])){
			length++;
		}
	}
	return (double)count/length;
}

double distanceEqn(double real_Frequencies[],double sentence[]){

        /*distance between two vectors formula in math: (square root of (((u1-v1)^2) + ((u2-v2)^2)))
                For two 26 space vectors it would go on until (square root of (((u26-v26)^2) + ((u26-v26)^2)):
                        use a for loop
        */
        //calculating the distance between the encoded sentence's frequencies and the (real) frequency vector

        double distanceCalculated = 0;
        for(int i=0; i<26; i++){
                distanceCalculated+=pow((real_Frequencies[i]-sentence[i]),2);
        }
        distanceCalculated = sqrt(distanceCalculated);
	return distanceCalculated;
} 

double num_shift(double distance[]){

        //for loop finds the lowest  

        int num_shift = 0;
        for(int i=1; i<26; i++){
                if(distance[i]<distance[num_shift]){
                        num_shift=i;
                }
        }
	return num_shift;
}	

	/*distance between two vectors formula in math: (square root of (((u1-v1)^2) + ((u2-v2)^2))) 
		For two 26 space vectors it would go on until (square root of (((u26-v26)^2) + ((u26-v26)^2)):
			use a for loop 
	
	//calculating the distance between the encoded sentence's frequencies and the (real) frequency vector
	double distanceCalculated = 0;
	for(int i=0; i<26; i++){
		distanceCalculated+=pow((real_Frequencies[i]-sentence[i]),2);
	}
	distanceCalculated = sqrt(distanceCalculated);


		//adding it to the distance vector (created above)
	for(int i=0; i<26; i++){
		distance[i] += distanceCalculated;
	}

	// wrong? 
	int charDistance = 0;
        for(int i=0; i<26; i++){
                charDistance+=sqrt(pow((real_Frequencies[i]-sentence[i]),2));
		distance[i]+=charDistance;
        }

	//for loop that goes through the distances (between each of the letters of encrypted frequences and real frequencies order a-z) 
		//and finds the lowest  
	int num_shift = 0;
	for(int i=1; i<26; i++){
		if(distance[i]<distance[num_shift]){
			num_shift=i;
		}
	}
	*/



