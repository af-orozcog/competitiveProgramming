#include<iostream>
#include<bitset>
#include<vector>
#include<algorithm>
#define ll long long

using namespace std;
typedef vector<int> vi;
bitset<1000002> bs;
vi primes;

void sieve(){
	bs.set();
	bs[0] = bs[1] = 0;
	for(ll i = 2; i <= 1000000;++i){
		if(bs[i]){
			for(ll j = i*i; j <= 1000000;j+=i) bs[j] = 0;
			primes.push_back(i);
		}
	}
}

pair<int,int> sum(int N){
	for(int i = 0; i < primes.size();++i){
		int look = N - primes[i];
		int index = lower_bound(primes.begin(),primes.end(),look) - primes.begin();
		if(primes[index] == look){
			return {primes[i],look};
		}
	}
	return {0,0};
}

int main(){
	sieve();
	while(1){
		//cout << "here" << endl;
		int N;
		scanf(" %d",&N);
		if(N == 0)
			break;
		pair<int,int> sol = sum(N);
		printf("%d = %d + %d\n",N, sol.first,sol.second);
	}
	return 0;
}