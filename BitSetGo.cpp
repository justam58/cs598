#include <iostream>
#include <math.h>

using namespace std;

bool const debug = false;

class BitSet{

private:
	int positive [1024];
	int negative [1024];

public:
	BitSet(){
		for(int i = 0; i < 1024; i++){
			positive[i] = 0;
			negative[i] = 0;
		}
	}

	void addToSet(int num){
		if(isInSet(num)){
			return;
		}
		if(num >= 0){
			int arrayPos = num / 32;
			int n1 = positive[arrayPos];
			int pos = num % 32;
			long n2 = 1 << pos;
			positive[arrayPos] = n1 | n2;
		}
		else{
			num = -num - 1;
			int arrayPos = num / 32;
			int n1 = negative[arrayPos];
			int pos = num % 32;
			long n2 = 1 << pos;
			negative[arrayPos] = n1 | n2;
		}
	}

	void removeFromSet(int num){
		if(!isInSet(num)){
			return;
		}
		if(num >= 0){
			int arrayPos = num / 32;
			int n1 = positive[arrayPos];
			int pos = num % 32;
			int n2 = 1 << pos;
			positive[arrayPos] = n1 - n2;
		}
		else{
			num = -num - 1;
			int arrayPos = num / 32;
			int n1 = negative[arrayPos];
			int pos = num % 32;
			int n2 = 1 << pos;
			negative[arrayPos] = n1 - n2;
		}
	}

	bool isInSet(int num){
		int n1;
		if(num >= 0){
			int arrayPos = num / 32;
			n1 = positive[arrayPos];
		}
		else{
			num = -num - 1;
			int arrayPos = num / 32;
			n1 = negative[arrayPos];
		}
		int pos = num % 32;
		long n2 = 1 << pos;
		return ((n1 & n2) == n2);
	}
};

int main() {
	BitSet nums;

	cout << "- - - - - PART I - - - - -" << endl;

	// 1.add every even short into set
	for(int i = -32768; i < 32768; i++){
		if(i % 2 == 0){
			nums.addToSet(i);
			if(!nums.isInSet(i)){
				cout << i << ": Somthing wrong with inserting. (Should be in the set!)" << endl;
			}
		}
		else{
			if(nums.isInSet(i)){
				cout << i << ": Somthing wrong with inserting. (Should not be in the set!)" << endl;
			}
		}
	}
	cout << "done adding every even short into set (including zero)" << endl;

	cout << "- - - - - PART II - - - - -" << endl;

	// 2.check if following numbers are in set the set
	int checks [] = {-32768, -20593, -4092, -983, -87, 0, 1, 15, 200, 350, 351, 378, 3957, 32767};
	for(int i = 0; i < 14; i++){
		if(i < 0) {
			i = -i;
		}
		if(nums.isInSet(checks[i])){
			cout << checks[i] << ":true" << endl;
		}
		else{
			cout << checks[i] << ":false" << endl;
		}
	}

	cout << "- - - - - PART III - - - - -" << endl;

	// 3.remove all the numbsers between -3000 and 4000
	for(int i = -3000; i < 4001; i++){
		nums.removeFromSet(i);
		if(nums.isInSet(i)){
			cout << i << ": Somthing wrong with removing. (Should not be in the set!)" << endl;
		}
	}

	cout << "done removing every short between -3000 and 4000 (include end points)" << endl;

	cout << "- - - - - PART IV - - - - -" << endl;

	// 4.check if following numbers are in set the set
	for(int i = 0; i < 14; i++){
		if(nums.isInSet(checks[i])){
			cout << checks[i] << ":true" << endl;
		}
		else{
			cout << checks[i] << ":false" << endl;
		}
	}
	return 0;
}