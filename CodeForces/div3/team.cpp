#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;

int analizer(int param[], int in, int size){
	if(param[in] == 0) return 0;
	int min = 120;
	int index = -1;
	for(int i = in + 1 ; i < size; i++){
		int dif = abs(param[in] - param[i]);
		if(dif < min){
			index = i;
			min = dif;
		}
	}
	param[in] = 0;
	param[index] = 0;
	return min;
}
bool wayToSort(int i, int j) { return i > j;}

int main(){
	int que;
	cin >> que;
	int num[que];
	for(int i = 0; i < que; i++){
		int val;
		cin >> val;
		num[i] = val;
	}
	sort(num, num + que, wayToSort);
	int sumTotal = 0;
	for(int i = 0; i < que; i++){
		sumTotal += analizer(num,i, que);
	}
	cout << sumTotal << endl;
}