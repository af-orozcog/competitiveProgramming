#include<stdio.h>
#include<string.h>
#define ll long long

ll nums[100005];

ll sum(int po){
	ll ans = 0;
	while(po){
		ans += nums[po];
		int dig = (po&(-po));
		po -= dig;
	}
	return ans;
}

void update(int po, ll val){
	while(po < 100005){
		nums[po] += val;
		int dig = (po&(-po));
		po += dig;
	}
}

int main(){
	int t;
	scanf(" %d",&t);
	while(t--){
		memset(nums,0,sizeof(nums));
		int n,u;
		scanf(" %d %d",&n,&u);
		while(u--){
			int l,r;
			ll val;
			scanf(" %d %d %lld",&l,&r,&val);
			++l;++r;
			update(l,val);
			update(r+1,-val);
		}
		int q;
		scanf(" %d",&q);
		while(q--){
			int val;
			scanf(" %d",&val);
			printf("%lld\n",sum(val+1));
		}
	}
	return 0;
}