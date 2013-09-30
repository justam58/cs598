#include <iostream>
#include <string.h>
#include <set>


using namespace std;

// int charToInt(char c){
// 	int result = -1;
// 	switch(c){
// 		case 'a': 
// 			result = 0;
// 			break;
// 		case 'b':
// 			result =  1;
// 			break;
// 		case 'c': 
// 			result =  2;
// 			break;
// 		case 'd': 
// 			result =  3;
// 			break;
// 		case 'e': 
// 			result =  4;
// 			break;
// 		case 'f': 
// 			result =  5;
// 			break;
// 		case 'g': 
// 			result =  6;
// 			break;
// 		case 'h': 
// 			result =  7;
// 			break;
// 		case 'i': 
// 			result =  8;
// 			break;
// 		case 'j': 
// 			result =  9;
// 			break;
// 		case 'k': 
// 			result =  10;
// 			break;
// 		case 'l': 
// 			result =  11;
// 			break;
// 		case 'm': 
// 			result =  12;
// 			break;
// 		case 'n': 
// 			result =  13;
// 			break;
// 		case 'o': 
// 			result =  14;
// 			break;
// 		case 'p': 
// 			result =  15;
// 			break;
// 		case 'q': 
// 			result =  16;
// 			break;
// 		case 'r': 
// 			result =  17;
// 			break;
// 		case 's': 
// 			result =  18;
// 			break;
// 		case 't': 
// 			result =  19;
// 			break;
// 		case 'u': 
// 			result =  20;
// 			break;
// 		case 'v': 
// 			result =  21;
// 			break;
// 		case 'w': 
// 			result =  22;
// 			break;
// 		case 'x': 
// 			result =  23;
// 			break;
// 		case 'y': 
// 			result =  24;
// 			break;
// 		case 'z': 
// 			result =  25;
// 			break;
// 		case 'A': 
// 			result =  0;
// 			break;
// 		case 'B':
// 			result =  1;
// 			break;
// 		case 'C': 
// 			result =  2;
// 			break;
// 		case 'D': 
// 			result =  3;
// 			break;
// 		case 'E': 
// 			result =  4;
// 			break;
// 		case 'F': 
// 			result =  5;
// 			break;
// 		case 'G': 
// 			result =  6;
// 			break;
// 		case 'H': 
// 			result =  7;
// 			break;
// 		case 'I': 
// 			result =  8;
// 			break;
// 		case 'J': 
// 			result =  9;
// 			break;
// 		case 'K': 
// 			result =  10;
// 			break;
// 		case 'L': 
// 			result =  11;
// 			break;
// 		case 'M': 
// 			result =  12;
// 			break;
// 		case 'N': 
// 			result =  13;
// 			break;
// 		case 'O': 
// 			result =  14;
// 			break;
// 		case 'P': 
// 			result =  15;
// 			break;
// 		case 'Q': 
// 			result =  16;
// 			break;
// 		case 'R': 
// 			result =  17;
// 			break;
// 		case 'S': 
// 			result =  18;
// 			break;
// 		case 'T': 
// 			result =  19;
// 			break;
// 		case 'U': 
// 			result =  20;
// 			break;
// 		case 'V': 
// 			result =  21;
// 			break;
// 		case 'W': 
// 			result =  22;
// 			break;
// 		case 'X': 
// 			result =  23;
// 			break;
// 		case 'Y': 
// 			result =  24;
// 			break;
// 		case 'Z': 
// 			result =  25;
// 			break;
// 	}
// 	return result;
// }

int main(int argc, char* argv[]) {

	string target;
	cin >> target;
	int* targetArr = new int[26];
	const char* targetCharArr = target.c_str();
	for(int i = 0; i < target.length(); i++){
		// int num = charToInt(targetCharArr[i]);
		int num = (int)targetCharArr[i];
		if(num > 90) {
			num = num - 32;
		}
		num = num - 65;
		targetArr[num]++;
	}

	string word;

	set<string> answers;

	while(cin >> word){
		if((word == "")|| (word == target) || (word.length() > target.length())){
			continue;
		}
		int* targetTempArr = new int[26];
		memcpy(targetTempArr, targetArr, 26 * sizeof(int));
		const char* wordCharArr = word.c_str();
		bool isAnswer = true;
		for(int i = 0; i < word.length(); i++){
			// int num = charToInt(wordCharArr[i]);
			int num = (int)wordCharArr[i];
			if(num > 90) {
				num = num - 32;
			}
			num = num - 65;
			if(num > 25 || num < 0){
				num = 26;
			}
			if(targetTempArr[num] > 0){
				targetTempArr[num]--;
			}
			else{
				isAnswer = false;
				break;
			}
		}
		if(isAnswer){
			answers.insert(word);
		}
		delete targetTempArr;
	}

	delete targetArr;
	cout << answers.size() << endl;
}

