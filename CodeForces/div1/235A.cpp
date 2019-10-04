#include<iostream>
#include<bitset>
#include<vector>
#include<set>
#define ll long long

using namespace std;
typedef vector<int> vi;
vi primes;
bitset<1000001> po;

void sieve(){
	po.set();
	po[0] = po[1] = 0;
	for(ll i = 2; i <= 1000000;++i){
		if(po[i]){
			for(ll j = i*i; j <= 1000000; j+= i) po[j] = 0;
			primes.push_back((int)i);
		}
	}
}

set<int> factorization(int n){
	set<int> ans;
	int tr = 0;
	while(primes[tr]*primes[tr] <= n){
		while(n % primes[tr] == 0){
			ans.insert(primes[tr]);
			n/= primes[tr];
		}
		++tr;
	}
	if(n != 1)
		ans.insert(n);
	return ans;
}

int main(){
	sieve();	
	int n;
	scanf(" %d",&n);
	set<int> used = factorization(n);
	ll ans = (ll)n;
	int co = 1;
	while(n > 0 && co < 3){
		bool pos = false;
		for(auto va: used){
			if(n % va != 0){
				pos = true;
				break;
			}
		}
		if(pos){
			ans *=(ll)n;
			set<int> add = factorization(n);
			for(auto va : used)
				used.insert(va);
			++co;
		}
		--n;
	}
	cout << ans << "\n";
	return 0;
}