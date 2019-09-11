#include<iostream>
#include<cstring>
#define ll long long

using namespace std;

ll nums[1000002];
ll used[1000002];
void update(int po, int val){
	while(po < 1000002){
		nums[po] += val;
		int dig = (po&(-po));
		po += dig;
	}
}

ll sum(int po){
	ll ans = 0;
	while(po){
		ans += nums[po];
		int dig = (po&(-po));
		po -= dig;
	}
	return ans;
}
void update2(int po, int val){
	while(po < 1000002){
		used[po] += val;
		int dig = (po&(-po));
		po += dig;
	}
}

ll sum2(int po){
	ll ans = 0;
	while(po){
		ans += used[po];
		int dig = (po&(-po));
		po -= dig;
	}
	return ans;
}

int main(){
	int n,m;
	scanf(" %d %d",&n,&m);
	memset(nums,0,sizeof(nums));
	while(n--){
		int l,r;
		scanf(" %d %d",&l,&r);
		update(l,1);
		update(r+1,-1);
	}
	while(m--){
		memset(used,0,sizeof(used));
		int ma;
		scanf(" %d",&ma);
		int ans = 0;
		for(int i = 0; i < ma;++i){
			int check; scanf(" %d",&check);
			if(sum(check)> 0 && ){
				++ans;
				cout << check << endl;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}