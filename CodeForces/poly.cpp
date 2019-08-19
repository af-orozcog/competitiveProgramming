#include<iostream>
#include<algorithm>
using namespace std;
int sumUpTo(int arreglo[],int from, int size){
	int answer = 0;
	for(int i = from; i < size;i++){
		answer += arreglo[i];
	}
	return answer;
}

int main(){
	int size;
	cin >> size;
	int posNums[size];
	int values[size-1];
	for(int i = 0; i < size-1;i++){
		int val;
		cin >> val;
		values[i] = val;
	}
	int plast = 2;
	for(int i = 0;i < size-1;i++){
		posNums[i] = plast - sumUpTo(values,i,size-1);
	}
	posNums[size-1] = plast;
	int n = sizeof(posNums) / sizeof(posNums[0]);
	sort(posNums,posNums+n);
	for(int i = 0; i < size-1; i++){
		if(posNums[i] == posNums[i+1]){
			cout << -1 << endl;
			return 0;
		}
	}
	for(int i = 0; i < size; i++){
		cout << posNums[i];
		if(i != size-1)
			cout << " ";
		else
			cout << endl;
	}
	return 0;
}