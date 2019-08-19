/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<vector>
#define ll long long

using namespace std;

struct node{
	ll sons = 0;
	ll dad = -1;
};

int main(){
	ll N,K;
	cin >> N >> K;
	vector<node> vals(N);
	for(int i = 0;i < N-1;++i){
		ll val1,val2;
		cin >> val1 >> val2;
		if(val1 > val2){
			ll temp = val1;
			val1 = val2;
			val2 = temp;
		}
		--val1;
		--val2;
		++vals[val1].sons;
		vals[val2].dad = val1;
	}
	for(int i = 0; i <N;++i){
		ll dad = vals[i].dad;
		ll ans = 0;
		while(dad != -1){
		//	cout << "dad is: " << dad << "dad's sons " << vals[dad].sons <<endl;
			if(vals[dad].sons >= K){
				ans = ans ^ (dad+ 1);
			}
			dad = vals[dad].dad;
		}
		cout << ans << endl;
	}
	return 0;
}