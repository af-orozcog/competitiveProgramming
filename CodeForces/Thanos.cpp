#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int elem;
	cin >> elem;
	int nume[elem];
	int flag = 0;
	for(int i = 0; i < elem; i++){
		int val;
		cin >> val;
		nume[i] = val;
	}
	int max = 1;
	for(int i = 2; i <= elem; i = i*2){
		for(int e = 0; e < elem/i;e++){
			int flag = 0;
			for(int j = (e*i)+1; j < (e*i)+i; j+=1){
				if(nume[j-1] > nume[j]){
					flag = 1;
					break;
				} 
			}

			if(flag == 0){
				max = i;
			}
		}
	}
	cout << max << endl;
}