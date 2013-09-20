#include <iostream>
#include <math.h>

using namespace std;

bool const debug = false;

class BitSet{

private:
	int positive [2];
	int negative [2];

public:
	BitSet(){
		for(int i = 0; i < 2; i++){
			positive[i] = 8;
			negative[i] = 0;
		}
	}

	void addToSet(int num){
		if(isInSet(num)){
			if(debug) cout << "adding: its already in the set!" << endl;
			return;
		}
		if(num >= 0){
			int arrayPos = num / 32;
			int n1 = positive[arrayPos];
			if(debug) cout << "adding: positive: I am now " << num << endl;	
			if(debug) cout << "adding: positive: I am in the " << arrayPos << " position with value " << n1 << endl;
			int pos = num % 32;
			if(debug) cout << "adding: positive: I am in the " << pos << " digit" << endl;
			long n2 = pow(2 , pos);
			if(debug) cout << "adding: positive: to OR values is " << n2 <<  endl;
			positive[arrayPos] = n1 | n2;
			if(debug) cout << "adding: positive: result: " << (n1 | n2) <<  endl;
		}
		else{
			num = -num - 1;
			if(debug) cout << "adding: negative: I am now " << num << endl;	
			int arrayPos = num / 32;
			int n1 = negative[arrayPos];
			if(debug) cout << "adding: negative: I am in the " << arrayPos << " position with value " << n1 << endl;
			int pos = num % 32;
			if(debug) cout << "adding: negative: I am in the " << pos << " digit" << endl;
			long n2 = pow(2 , pos);
			if(debug) cout << "adding: negative: to OR values is " << n2 <<  endl;
			negative[arrayPos] = n1 | n2;
			if(debug) cout << "adding: negative: result: " << (n1 | n2) <<  endl;
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
			int n2 = pow(2 , pos);
			positive[arrayPos] = n1 - n2;
		}
		else{
			num = -num - 1;
			int arrayPos = num / 32;
			int n1 = negative[arrayPos];
			int pos = num % 32;
			int n2 = pow(2 , pos);
			negative[arrayPos] = n1 - n2;
		}
	}

	bool isInSet(int num){
		int n1;
		if(num >= 0){
			if(debug) cout << "checking: positive: I am now " << num << endl;	
			int arrayPos = num / 32;
			n1 = positive[arrayPos];
			if(debug) cout << "checking: positive: I am in the " << arrayPos << " position with value " << n1 << endl;
		}
		else{
			num = -num - 1;
			if(debug) cout << "checking: negative: I am now " << num << endl;
			int arrayPos = num / 32;
			n1 = negative[arrayPos];
			if(debug) cout << "checking: negative: I am in the " << arrayPos << " position with value " << n1 << endl;
		}
		int pos = num % 32;
		if(debug) cout << "checking: I am in the " << pos << " digit" << endl;
		long n2 = pow(2 , pos);
		if(debug) cout << "checking: to AND values is " << n2 <<  endl;
		if(debug) cout << "checking: after ANDing is " << (n1 & n2) <<  endl;
		if(debug) cout << "checking: result: " << ((n1 & n2) == n2) <<  endl;
		return ((n1 & n2) == n2);
	}
};

int main() {
	BitSet nums;

	// cout << "- - - - - TEST - - - - -" << endl;	
	// cout << nums.isInSet(0) << endl;
	// cout << nums.isInSet(3) << endl;
	// cout << nums.isInSet(5) << endl;

	cout << "- - - - - PART I - - - - -" << endl;

	// 1.add every even short into set
	//for(int i = -32768; i < 32768; i++){
	for(int i = -64; i < 63; i++){
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

	// cout << "- - - - - PART II - - - - -" << endl;

	// // 2.check if following numbers are in set the set
	// int checks [] = {-32768, -20593, -4092, -983, -87, 0, 1, 15, 200, 350, 351, 378, 3957, 32767};
	// for(int i = 0; i < 14; i++){
	// 	if(i < 0) {
	// 		i = -i;
	// 	}
	// 	if(nums.isInSet(checks[i])){
	// 		cout << "true" << endl;
	// 	}
	// 	else{
	// 		cout << "false" << endl;
	// 	}
	// }

	// cout << "- - - - - PART III - - - - -" << endl;

	// // 3.remove all the numbsers between -3000 and 4000
	// for(int i = -3000; i < 4001; i++){
	// 	nums.removeFromSet(i);
	// 	if(nums.isInSet(i)){
	// 		cout << i << ": Somthing wrong with removing. (Should not be in the set!)" << endl;
	// 	}
	// }

	// cout << "- - - - - PART IV - - - - -" << endl;

	// // 4.check if following numbers are in set the set
	// for(int i = 0; i < 14; i++){
	// 	if(nums.isInSet(checks[i])){
	// 		cout << "true" << endl;
	// 	}
	// 	else{
	// 		cout << "false" << endl;
	// 	}
	// }
	return 0;
}