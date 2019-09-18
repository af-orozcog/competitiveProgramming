#include<iostream>
#include<vector>
#include<bitset>
#include<algorithm>

using namespace std;
typedef vector<int> vi;
bitset<100002> po;
vi primes;

void sieve(){
	po.set();
	bo[0] = bo[1] = 0;
	for(int i = 2; i < 100002;++i){
		if(po[i]){
			for(int j = i*i; i < 100002;j+=i) po[j] = 0;
			primes.push_back(i);
		}
	}
}

int pri(int n){
	for(int i = 0; i < n;++i){
		if(n % primes[i] == 0)
			return i;
	}
}

int main(){
	sieve();
	int siz;
	scanf(" %d",&siz);
	for(int i = 2; i < siz+1;++i){
		int va = pri(i);
		int in = lower_bound(pri.begin(),pri.end(),va) - pri.begin();
		if(i == 2)
			printf("%d", in+1);
		else
			printf(" %d",in+1);
	}
	return 0;
}