/**
* I only hope everything will be back to normal
*/
#include<bits/stdc++.h>
#define ll long long

using namespace std;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
typedef vector<vector<pii>> vpii;
vector<int> pos;

void init(){
	int upto = (1<<7);
	for(int i = 1; i < upto;++i){
		int tot = 0;
		int j = 1;
		int co = i;
		while(co){
			if(co&1)
				tot += j;
			j*=10;
			co = co >> 1;
		}
		pos.push_back(tot);
	}
}

int main(){
	init();
	int n;
	scanf(" %d",&n);
	vector<int> ans;
	while(n){
		int take = lower_bound(pos.begin(),pos.end(),n)-pos.begin();
		if(pos[take] > n)
			--take;
		take = pos[take];
		n-= take;
		ans.push_back(take);
	}
	cout << ans.size() << endl;
	for(auto va:ans)
		printf("%d ",va);
	return 0;
}