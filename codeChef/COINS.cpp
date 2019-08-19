/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<map>
#define max(x,y)(x > y?x:y)
#define ll long long

using namespace std;

map<ll,ll> memo;

ll solve(ll val){
	//cout << val << endl;
	if(val == 0)
		return 0;
	if(memo.count(val) == 1 && memo[val] != 0)
		return memo[val];
	else{
		ll m = solve(val/2)+ solve(val/3) +solve(val/4);
		return memo[val] = max(val,m);
	}
}

int main(){
	ll val;
	while(cin >> val){
		if(memo.count(val)){
			cout << memo[val] << endl;
			continue;
		}
		memo[val] = solve(val);
		cout << memo[val] << endl;
	}
	return 0;
}