#include<iostream>
#include<bitset>
#include<vector>
#include<algorithm>
#define ll long long

using namespace std;
vector<int> primes;
bitset<10000010> bs;
vector<pair<int,int>> par;

void sieve(){
	bs.set();
	bs[0] = bs[1] = 0;
	for(ll i = 2;i <= 10000000;++i){
		if(bs[i]){
			for(ll j = i*i; j <=10000000;j += i) bs[j] = 0;
			primes.push_back((int)i);
		}
	}
}

bool prime(int n){
	if(n <= primes[primes.size()-1]){
		int index = lower_bound(primes.begin(),primes.end(),n) - primes.begin();
		if(primes[index] == n)
			return true;
		return false;
	}
	for(int i = 0;i < primes.size();++i){
		if(primes[i]*primes[i] > n)
			break;
		if(n % primes[i] == 0)
			return false;
	}
	return true;
}

void create(){
	//cout << primes[primes.size()-1] << endl;
	for(int i = 0; i < primes.size()-1;++i){
		if(primes[i] +2 == primes[i+1])
			par.push_back({primes[i],primes[i]+2});
	}
	for(int i = 10000001; i <= 20000000;i+=2){
		if(prime(i) && prime(i+2)){
			par.push_back({i,i+2});
			//cout << "entro?" << endl;
		}
	}
	//cout <<par.size()<< endl;
}

int main(){
	sieve();
	create();
	int n;
	while(scanf(" %d",&n) == 1)
		printf("(%d, %d)\n",par[n-1].first,par[n-1].second);
	return 0;
}