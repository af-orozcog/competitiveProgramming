#include<iostream>
#include<vector>
#include<bitset>
#include<string>
#include<algorithm>
#define ll long long

using namespace std;
bitset<10000001> bs;
vector<int> primes;

void sieve(){
	bs.set();
	bs[0] = bs[1] = 0;
	for(ll i = 2; i < 10000001;++i){
		if(bs[i]){
			for(ll j = i*i; j < 10000001;j+=i)bs[j] = 0;
			primes.push_back((int)i);
		}
	}
}

int next(int n){
	int index = lower_bound(primes.begin(),primes.end(),n)-primes.begin();
	if(primes[index] == n)
		++index;
	while(index < primes.size()){
		int num = primes[index];
		string nem = to_string(num);
		cout << "nem " << nem << endl;
		bool yes = true;
		for(int i = 1; i < nem.size();++i){
			char last = nem[nem.size()-1];
			for(int j = nem.size()-1; j > 0;--j)
				nem[j] = nem[j-1];
			nem[0] = last;
			int look = stoi(nem);
			cout << look << endl;
			int index2 = lower_bound(primes.begin(),primes.end(),look)-primes.begin();
			if(primes[index2] != look){
				yes = false;
				break;
			}
		}
		if(yes)
			return num;
		++index;
	}
	return 0;
}

int main(){
	sieve();
	while(1){
		int n;
		scanf(" %d",&n);
		if(!n)
			break;
		printf("%d\n",next(n));
	}
	return 0;
}