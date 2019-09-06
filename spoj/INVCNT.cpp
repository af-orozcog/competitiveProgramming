#include<iostream>
#include<cstring>
#define ll long long

using namespace std;

ll nums[10000002];

ll sum(int i){
	ll sum = 0;
	while(i){
		sum+= nums[i];
		int dig = (i & (-i));
		i -=  dig;
	}
	return sum;
}

ll summation(int i, int j){
	return sum(j) - sum(i-1);
}

void change(int i){
	while(i <= 10000000){
		++nums[i];
		int dig = (i&(-i));
		i += dig;
	}
}

int main(){
	int t;
	scanf(" %d",&t);
	while(t--){
		memset(nums,0,sizeof(nums));
		int n;
		scanf(" %d",&n);
		ll ans = 0;
		for(int i = 0; i< n;++i){
			int val;
			scanf(" %d",&val);
			if(val == 10000000)
				continue;
			change(val);
			ans += summation(val+1,10000000);
		}
		printf("%lld\n",ans);
	}	
	return 0;
}