#include<iostream>
#define ll long long 
using namespace std;
int main(){
	int cases;
	cin >> cases;
	for(int i = 0; i < cases;i++){
		ll val1,val2;
		cin >> val1 >> val2;
		char answer = val1==val2? '=':val1 < val2 ? '<':'>';
		cout << answer << endl; 
	}
	return 0;
}