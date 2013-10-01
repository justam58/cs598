#include <iostream>
#include <string.h>
#include <set>
#include <map>


using namespace std;

int main(int argc, char* argv[]) {

	string target;
	cin >> target;
	map<char,int> targetArr;
	const char* targetCharArr = target.c_str();
	for(int i = 0; i < target.length(); i++){
		targetArr[targetCharArr[i]]++;
	}

	string word;
	set<string> answers;

	while(cin >> word){
		if((word == "")|| (word == target) || (word.length() > target.length())){
			continue;
		}
		map<char,int> targetTempArr;
		targetTempArr.insert(targetArr.begin(),targetArr.end());
		const char* wordCharArr = word.c_str();
		bool isAnswer = true;
		for(int i = 0; i < word.length(); i++){
			if(targetTempArr[wordCharArr[i]] > 0){
				targetTempArr[wordCharArr[i]]--;
			}
			else{
				isAnswer = false;
				break;
			}
		}
		if(isAnswer){
			answers.insert(word);
		}
	}
	cout << answers.size() << endl;
}

