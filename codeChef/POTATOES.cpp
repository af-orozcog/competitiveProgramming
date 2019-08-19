/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>

using namespace std;
bitset<2500> pos;
vector<int> primes;

void sieve(){
	pos.set();
	for(int i = 2; i <2500;++i){
		if(pos[i]){
			int m = 2;
			while(i * m < 2500){
				pos.set(i*m,0);
				++m;
			}
			primes.push_back(i);
		}
	}
}

int main(){
	sieve();
	int cas;
	scanf("%d",&cas);
	while(cas--){
		int h1,h2;
		scanf(" %d %d",&h1,&h2);
		int sum = h1 + h2 + 1;
		vector<int>::iterator low = lower_bound(primes.begin(),primes.end(),sum);
		int val = primes[low - primes.begin()];
		printf("%d\n",val - sum + 1);
	}
	return 0;
}