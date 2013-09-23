#include <iostream>
#include <map>
#include <set>
#include <utility>

using namespace std;

int main(int argc, char* argv[]) {

	map< int,set<long long int> > numMap;

	int nums;
	cin >> nums;

	for(int i = 0; i < nums; i++){
		long long int num;
		cin >> num;
		long long int temp = num;
		int digitFound [10];
		for(int j = 0; j < 10; j++){
			digitFound[j] = 0;
		}
		while(temp > 0){
			int digit = temp % 10;
			if(digitFound[digit] == 0){
				numMap[digit].insert(num);
				digitFound[digit] = 1;
			}
			temp = temp / 10;
		}
	}

	typedef map<int, set<long long int> >::iterator it_type;
	for(it_type iterator = numMap.begin(); iterator != numMap.end(); iterator++) {
		int size = iterator->second.size();
		int temp = (size * (size-1)) / 2;
		cout << temp << endl;
		ans += temp;
	}
	cout << ans << endl;
}