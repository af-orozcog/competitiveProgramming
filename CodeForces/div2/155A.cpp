/**
* I'm sorry I was an Idiot
*/
#include<iostream>

using namespace std;

int main(){
	int cas;
	cin >> cas;
	int ama = 0;
	int max,min;
	cin >> max;
	min = max;
	--cas;
	while(cas--){
		int val;
		cin >> val;
		if(val > max){
			++ama;
			max = val;
		}
		else if(val < min){
			++ama;
			min = val;
		}
	}
	cout << ama << endl;
	return 0;
}