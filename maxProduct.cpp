#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

void quickSort(int* array, int left, int right) {
    int i = left;
	int j = right;
	int tmp;
	int pivotPos = (left + right) / 2;
	int pivot = array[pivotPos];

	while(i <= j) {
		while(array[i] < pivot) {
			i++;
		}
		while(array[j] > pivot) {
			j--;
		}
		if(i <= j) {
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			i++;
			j--;
		}
	}

	if(left < j) {
		quickSort(array, left, j);
	}

	if(i < right) {
		quickSort(array, i, right);
	}
}

int main(int argc, char* argv[]) {
	int tests;
	cin >> tests;
	int* answer = new int[tests];
	cin.ignore();
	for(int i = 0; i < tests; i++) {
		string input;
		getline(cin,input);
		vector<string> nums;
		istringstream iss(input);
	    	copy(istream_iterator<string>(iss), 
			 istream_iterator<string>(),
		 back_inserter<vector<string> >(nums));

		int* array = new int[nums.size()];
		for(int j = 0; j < nums.size(); j++) {
			stringstream ss;
			ss << nums.at(j);
			int num;
			ss >> num;
			array[j] = num;
		}
		if(nums.size() == 2){
			answer[i] = array[0] * array[1];
		}
		else if(nums.size() == 1){
			answer[i] = array[0];
		}
		else{
	    		quickSort(array, 0, nums.size()-1);
			int pos1 = array[nums.size()-1] * array[nums.size()-2] * array[nums.size()-3];
			int pos2 = array[0] * array[1] * array[nums.size()-1];
			answer[i] = max(pos1,pos2);
		}
	}
	for(int i = 0; i < tests; i++){
		cout << answer[i] << endl;
	}
}
