#include<iostream>
#include<vector>
#include<bitset>
#include<algorithm>
#define ll long long


using namespace std;
typedef vector<int> vi;
bitset<100002> po;
vi primes;

void sieve(){
	po.set();
	po[0] = po[1] = 0;
	for(ll i = 2; i < 100002;++i){
		if(po[i]){
			for(ll j = i*i; j < 100002;j+=i) po[j] = 0;
			primes.push_back((int)i);
		}
	}
}

int pri(int n){
	for(int i = 0; i < primes.size();++i){
		if(n % primes[i] == 0)
			return primes[i];
	}
}

int main(){
	sieve();
	int siz;
	scanf(" %d",&siz);
	for(int i = 2; i < siz+1;++i){
		int va = pri(i);

		int in = lower_bound(primes.begin(),primes.end(),va) - primes.begin();
		if(i == 2)
			printf("%d", in+1);
		else
			printf(" %d",in+1);
	}
	puts("");
	return 0;
}