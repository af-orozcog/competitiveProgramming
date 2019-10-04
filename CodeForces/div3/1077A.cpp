//ALL I DO IS WRONG
#include<iostream>
#define ll long long

using namespace std;

int main(){
	int t;
	scanf(" %d",&t);
	while(t--){
		int a,b,k;
		cin >> a >> b >> k; 
		ll efe = a-b;
		ll mov = efe*(k>>1);
		cout << (mov +(k&1 == 1? a:0)) << endl;
	}
	return 0;
}