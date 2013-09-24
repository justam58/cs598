#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

	int* inputs = new int[1024];

	int nums;
	cin >> nums;

	for(int i = 0; i < nums; i++){
		long long int num;
		cin >> num;
		int index = 0;
		while((num >= 1)){
			int digit = num % 10;
			index = index | (1 << digit);
			if(index == 1023){
				break;
			}
			num = num / 10;
		}
		inputs[index]++;	
	}
	long long int answer = 0;
	for(int i = 0; i < 1024; i++){
		for(int j = i; j < 1024; j++){
			if(i == j){
				answer += inputs[i] * (inputs[j]-1) / 2;
			}
			else{
				bool found = false;
				for(int k; k < 10; k++){
					if(((i >> k) & 1 == 1) && ((j >> k) & 1 == 1)){
						found = true;
						break;
					}
					if(found){
						answer += inputs[i] * inputs[j];
					}
				}
			}
		}
	}

	cout << answer << endl;
}