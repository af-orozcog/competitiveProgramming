/**
* I only hope everything will be back to normal
*/
#include<bits/stdc++.h>
#define ll long long

using namespace std;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
typedef vector<vector<pii>> vpii;

int main(){
	ll num = 3;
	ll com = 1000000000000000000;
	int i = 1;
	while(num <= com){
		num*=3;
		cout << num <<" " <<i<<endl;
		++i;
	}
	return 0;
}