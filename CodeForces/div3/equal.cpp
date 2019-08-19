#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	int man;
	cin >> man;
	int numbers[man];
	for(int i = 0;i < man; i++){
		int val;
		cin >> val;
		numbers[i] = val;
	}
	int n = sizeof(numbers) / sizeof(numbers[0]);
	sort(numbers,numbers+n);
	int flag = 0;
	int different1 = 0;
	vector<int> different2;
	for(int i = 0; i < man; i++){
		if(i == man -1){
			different1++;
			different2.push_back(numbers[i]);
		}
		else if(numbers[i] != numbers[i+1]){
			different2.push_back(numbers[i]);
			different1++;
		}
	}
	if(different1 > 3){
		cout << -1 << endl;
		return 0;
	}
	if(different1 == 2){
		int first = different2[0];
		int second = different2[1];
		int posi = (first + second)/ 2;
		if(abs(first - posi) == abs(second -posi)){
			cout << abs(first - posi) << endl;
			return 0;
		}
		cout << abs(first -second) << endl;
		return 0;
	}
	if(different1 == 1){
		cout <<  0 << endl;
		return 0;
	}
	if(abs(different2[0] - different2[1]) == abs(different2[1] - different2[2])){
		cout << abs(different2[0] - different2[1]) << endl;
		return 0;
	}
	cout << -1 << endl;
	return 0;
}