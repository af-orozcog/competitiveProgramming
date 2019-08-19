#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int cases;
	cin >> cases;
	while(cases--){
		int val; 
		cin >> val;
		int answer = (((((val * 567)/9) + 7492) * 235)/47)-498;
		answer = (answer / 10)%10;
		cout << abs(answer) << endl;
	}
	return 0;	
}
