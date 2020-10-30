#include <iostream>
#include <cmath>
#include <vector>
#include "decode.h"
#include "decrypt.h"

//charFrequency is the number of times a letter appears divided by the total number of letters * 100 (for percentage): for the encrypted sentence
double charfrequencyEncryption(std::string encryptedStr, char letter){
	int count = 0;
	for(int i=0; i<encryptedStr.length(); i++){
		if(encryptedStr[i]==letter){
			count++;
                }
	}
	return (count/(encryptedStr.length()+1)*100);
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
        //for loop that goes through the distances (between each of the letters of encrypted frequences and real frequencies order a-z)
                //and finds the lowest  
        int num_shift = 0;
        for(int i=1; i<26; i++){
                if(distance[i]<distance[num_shift]){
                        num_shift=i;
                }
        }
	return num_shift;
}

std::string decode(std::string encryptedStr){
	double real_Frequencies[26] = {8.2, 1.5, 2.8, 4.3, 13,2.2, 2, 6.1, 7, 0.15,0.77, 4, 2.4, 6.7, 7.5,1.9, 0.095, 6, 6.3, 9.1,2.8, 0.98, 2.4, 0.15, 2,0.074};
	char alphabet [26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	double sentence[26]; //storing frequencies of encrypted sentence here
	double distance[26]; 
	std::string encryptedStr2;	

	
	//adding the frequency to vector: sentence using above function charfrequencyEncryption
	for(int i=0;i<26;i++){
		encryptedStr2 = decryptCaesar(encryptedStr, i);

		for(int j=0; j<26; j++){
			sentence[j]+=charfrequencyEncryption(encryptedStr2, alphabet[j]);
		}
		distance[i] = distanceEqn(real_Frequencies,sentence);
	}
	
        int shift = num_shift(distance);

        return decryptCaesar(encryptedStr, shift);





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

}

