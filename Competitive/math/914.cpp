#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<bitset>
#define ll long long

using namespace std;
bitset<1000100> bs;
vector<int> primes;

void sieve(){
	bs.set();
	bs[0] = bs[1] = 0;
	for(ll i = 2; i <= 1000099;++i){
		if(bs[i]){
			for(ll j = i*i; j <=1000099;j+=i) bs[j] = 0;
			primes.push_back((int)i);
		}
	}
}

int main(){
	int t;
	sieve();
	scanf(" %d",&t);
	while(t--){
		int l,u;
		scanf(" %d %d",&l,&u);
		int indexl = lower_bound(primes.begin(),primes.end(),l) - primes.begin();
		int indexU = upper_bound(primes.begin(),primes.end(),u) - primes.begin() -1;
		if(indexl >= indexU){
			puts("No jumping champion");
			continue;
		}
		map<int,int> freq;	
		int most = 0;
		for(int i = indexl; i < indexU;++i){
			int dif = primes[i+1] - primes[i];
			if(freq.count(dif))
				++freq[dif];
			else
				freq[dif] = 1;
			if(most < freq[dif])
				most = freq[dif];
		}
		int ans = -1;
		for(const auto &pa: freq){
			if(pa.second == most){
				if(ans == -1)
					ans = pa.first;
				else
					ans = 0;
			}
		}
		if(ans == 0)
			puts("No jumping champion");
		else
			printf("The jumping champion is %d\n",ans);
	}
	return 0;
}