#include<iostream>
#include<bitset>
#include<vector>
#include<algorithm>

using namespace std;
typedef vector<int> vi;

bitset<1001> bs;
vi primes;

void sieve(){
	bs.set();
	bs[0] = bs[1];
	primes.push_back(1);
	for(int i = 2; i <= 1000;++i){
		if(bs[i]){
			for(int j = i*i; j <= 1000;j+=i) bs[j] = 0;
			primes.push_back(i);
		}
	}
}

int main(){
	sieve();
	int N,C;
	int fi = 1;
	while(scanf(" %d %d",&N,&C) == 2){
		printf("%d %d:",N,C);
		int index = upper_bound(primes.begin(),primes.end(),N)-primes.begin();
		int size = index;
		//cout <<"size is" <<size << " "<< primes[size-1]<<endl;
		int many = C<<1;
		if(index & 1)
			many = (C << 1)-1;
		if(many > index)
			many = index;
		for(int i = index/2-many/2,j=0; j < many;++i,++j)
			printf(" %d", primes[i]);
		puts("");
		puts("");
	}
}