#include<iostream>
#include<cmath>
#define ll long long

using namespace std;

int main(){
	int n;
	scanf(" %d",&n);
	int mul = 1;
	ll coins= 0;
	ll zero = 0;
	for(int i = 0; i < n;++i){
		int v;
		scanf(" %d",&v);
		if(v == 0)
			++zero;
		else if(v < 0){
			mul *= -1;
			coins += abs(-1-v);
		}
		else
			coins += abs(1-v);
	}
	if(mul == 1)
		cout << coins + zero << endl;
	else{
		if(zero != 0)
			cout << coins + zero << endl;
		else
			cout << coins +2 << endl;
	}
	return 0;
}