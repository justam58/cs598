#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(int argc, char* argv[]) {

	string word1;
	while(cin >> word1){
		int* answers = new int[26];
		for(int i = 0; i < 26; i++){
			answers[i] = 0;
		}
		int* word1Arr = new int[26];
		const char* word1Char = word1.c_str();
		for(int i = 0; i < 26; i++){
			word1Arr[i] = 0;
		}
		for(int i = 0; i < word1.length(); i++){
			int num = (int)word1Char[i];
			num = num - 97;
			word1Arr[num]++;
		}

		string word2;
		cin >> word2;
		int* word2Arr = new int[26];
		const char* word2Char = word2.c_str();
		for(int i = 0; i < word2.length(); i++){
			int num = (int)word2Char[i];
			num = num - 97;
			if(word1Arr[num] > 0){
				word1Arr[num]--;
				answers[num]++;
			}
		}

		for(int i = 0; i < 26; i++){
			while(answers[i] > 0){
				cout << (char)(i+97);
				answers[i]--;
			}
		}
		cout << endl;
		delete answers;
		delete word1Arr;
		delete word2Arr;
	}
}