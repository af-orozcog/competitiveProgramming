/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long

using namespace std;

int main(){
	int cas;
	cin >> cas;
	while(cas--){
		ll N,M;
		cin >> N >> M;
		vector<ll> stored(M);
		for(int i = 0; i < M;++i){
			cin >> stored[i];
		}
		vector<ll> toSell(N);
		ll total = 0;
		for(int i = 0; i < N;++i){
			int D,F,B;
			cin >> D >> F >> B;
			if(stored[D-1] > 0){
				toSell[i] = D;
				total += F;
				--stored[D-1];
			}
			else{
				total += B;
				toSell[i] = -1;
			}
		}
		ll j = 0;
		cout << total << endl;
		for(int i = 0; i < N;++i){
			if(i == 0)
				cout << toSell[i];
			else{
				if(toSell[i] != -1)
					cout << " " << toSell[i];
				else{
					while(stored[j] == 0){
						++j;
					}
					cout << " " << j + 1;
					stored[j] -= 1;
				}
			}
		}
		cout << endl;
	}
	return 0;
}