#include<iostream>
#include<vector>
#include<bitset>
#include<algorithm>
#define ll long long

using namespace std;
typedef vector<int> vi;

bitset<40001> bs;
vi primes;

void sieve(){
	bs.set();
	bs[0] = bs[1];
	for(ll i = 2; i <= 40000;++i){
		if(bs[i]){
			for(ll j = i*i;j<= 40000;j+=i) bs[j] = 0;
			primes.push_back((int)i);
		}
	}
}

int countPairs(int N){
	int to = N>>1;
	int ans = 0;
	for(int i = 0; i < primes.size();++i){
		if(primes[i] > to)
			break;
		//cout << to << endl;
		int look = N - primes[i];
		int index = lower_bound(primes.begin(),primes.end(),look)-primes.begin();
		if(primes[index] == look)
			++ans;
	}
	return ans;
}

int main(){
	sieve();
	while(1){
		int n;
		scanf(" %d",&n);
		if(!n)
			break;
		printf("%d\n",countPairs(n));
	}
	return 0;
}