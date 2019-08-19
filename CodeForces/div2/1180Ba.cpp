/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#define abs(x)(x < 0? -x:x)

using namespace std;

int main(){
	int siz;
	cin >> siz;
	int nums[siz];
	int ind = -1;
	int max = 0;
	for(int i = 0; i < siz;++i){
		cin >> nums[i];
		if(nums[i] >= 0)
			nums[i] = (-nums[i]) - 1;
		if(abs(nums[i]) > max){
			max = abs(nums[i]);
			ind = i;
		}
	}
	//cout << siz % 2 
	if(siz % 2){
		nums[ind] = (-nums[ind]) - 1;
	}
	for(int i = 0; i < siz;++i){
		if(i == 0)
			cout << nums[i];
		else
			cout << " " << nums[i];
	}
	cout << endl;
	return 0;
}