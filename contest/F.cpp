#include<iostream>
#include<cstring>
#define ll long long

using namespace std;

ll nums[1000002];


ll sum(int k){
	ll ans = 0;
	while(k){
		ans += nums[k];
		int less = (k&(-k));
		k -= less;
	}
	return ans;
}

void update(int pos,ll val){
	while(pos < 1000002){
		nums[pos] += val;
		int add = (pos&(-pos));
		pos+= add;
	}
}

ll summation(int i, int j){
	return sum(j) - sum(i-1);
}


int main(){
	int N;
	scanf(" %d",&N);
	memset(nums,0,sizeof(nums));
	for(int i = 1; i <= N;++i){
		ll re;
		scanf(" %lld",&re);
		update(i,re);
	}
	int q;
	scanf(" %d",&q);
	while(q--){
		char va;
		ll a,b;
		scanf(" %c %lld %lld",&va,&a,&b);
		if(va == 'q')
			printf("%lld\n",summation((int)a,(int)b));
		else
			update((int)a,b);
	}
	return 0;
}