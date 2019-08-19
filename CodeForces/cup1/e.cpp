#include<iostream>

using namespace std;

int main(){
	int n,q;
	cin >> n >> q;
	int nums[n];
	for(int i = 0; i< n;i++){
		int val;
		cin >> val;
		nums[i] = val;
	}
	for(int i = 0; i< q;i++){
		string com;
		int num;
		cin >> com >> num;
		for(int j = 0; j < n;j++){
			if(com[0] == '>'){
				if(nums[j] > num){
					nums[j] = -nums[j];
				}
			}
			else{
				if(nums[j] < num)
					nums[j] = -nums[j];
			}
		}
	}
	cout << nums[0];
	for(int i = 1; i < n;i++){
		cout << " "<< nums[i];
	}
	cout << endl;
	return 0;
}