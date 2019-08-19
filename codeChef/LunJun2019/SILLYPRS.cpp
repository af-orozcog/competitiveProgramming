#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
#define min(x,y)(x < y? x:y)

using namespace std;

bool com(const ll a, const ll b){
	return a > b;
}

int main(){
	int cas;
	scanf(" %d",&cas);
	while(cas--){
		ll N;
		scanf(" %lld",&N);
		vector<ll> oneEven;
		vector<ll> oneOdd;
		vector<ll> twoEven;
		vector<ll> twoOdd;
		for(int i = 0;i < N;++i){
			ll val;
			scanf(" %lld",&val);
			if(val & 1)
				oneOdd.push_back(val);
			else
				oneEven.push_back(val);
		}
		for(int i = 0;i < N;++i){
			ll val;
			scanf(" %lld",&val);
			if(val & 1)
				twoOdd.push_back(val);
			else
				twoEven.push_back(val);
		}
		sort(oneOdd.begin(),oneOdd.end(),com);
		sort(oneEven.begin(),oneEven.end(),com);
		sort(twoEven.begin(),twoEven.end(),com);
		sort(twoOdd.begin(),twoOdd.end(),com);
		int to = min(oneOdd.size(),twoOdd.size());
		ll total = 0;
		for(int i = 0; i < to;++i){
			total += ((oneOdd[i]+twoOdd[i]) >> 1);
		}
		to = min(oneEven.size(),twoEven.size());
		for(int i = 0; i < to;++i){
			total += ((oneEven[i] + twoEven[i]) >> 1);
		}
		if(oneOdd.size() > twoOdd.size()){
			int from1 = oneOdd.size() - (oneOdd.size() - twoOdd.size());
			int from2 = twoEven.size() - (twoEven.size() - oneEven.size());
			for(int i = 0; i + from1 < oneOdd.size();++i){
				total += ((oneOdd[i+from1]+twoEven[i+from2]) >> 1);
			}
		}
		else if(oneEven.size() > twoEven.size()){
			int from1 = oneEven.size() - (oneEven.size() - twoEven.size());
			int from2 = twoOdd.size() - (twoOdd.size() - oneOdd.size());
			for(int i = 0; i + from1 < oneEven.size();++i){
				total += ((oneEven[i+from1]+twoOdd[i+from2]) >> 1);
			}
		}
		printf("%lld\n",total);
	}
	return 0;
}