/**
* about to lose ranking
*/
#include<iostream>
#include<vector>

using namespace std;

int main(){
	int N,K;
	cin >> N >> K;
	int max = N >> 1;
	if(N & 1)
		max += 1;
	vector<int> drinks(K,0);
	for(int i = 0; i < N;++i){
		int val;
		cin >> val;
		--val;
		++drinks[val];
	}
	int ans = 0;
	for(int i = 0; i < K && max;++i){
		if(drinks[i] >=2){
			ans+=2;
			drinks[i]-=2;
			--max;
			--i;
		}
	}
	for(int i = 0; i < K && max;++i){
		if(drinks[i] > 0){
			++ans;
			--max;
		}
	}
	cout << ans << endl;
	return 0;
}