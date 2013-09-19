#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
	string result = "";
	int tests;
	cin >> tests;
	map<int,int> answers;
	for(int i = 0; i < tests; i++) {
		int a;
		cin >> a;
		cin.ignore();
		int b;
		cin >> b;
		int ans = 0;
		for(int j = a; j <= b; j++){
			if(answers[j] == 0){	
				int count;
				int n = j;
				vector<int> temps;
				for (count = 0; n != 1; count++) {
					temps.push_back(n);
				    if(n % 2 == 0){
						n = n / 2;
				    } 
				    else {
						n = 3 * n + 1;
				    }
				}
				for(int k = 0; k < temps.size(); k++){
					answers[temps.at(k)] = count;
					count--;
				}
			}
			ans = max(ans,answers[j]);
		}
		stringstream ss;
		ss << ans;
		string ansStr;
		ss >> ansStr;
		result += ansStr + "\n";
	}
	cout << result;
}
