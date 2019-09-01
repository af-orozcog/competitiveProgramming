#include<iostream>
#include<vector>
#include<string>
#include<bitset>
#include<algorithm>
#define ll long long

using namespace std;
typedef vector<int> vi;
vi primes;
bitset<10000001> bs;

void sieve(){
	bs.set();
	bs[0] = bs[1] = 0;
	for(ll i = 2; i <= 10000000;++i){
		if(bs[i]){
			for(ll j = i*i; j <= 10000000; j+= i) bs[j] = 0;
			primes.push_back(i);
		}
	}
}



int main(){
	sieve();

}