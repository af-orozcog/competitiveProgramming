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

int main(){
	int n;
	scanf(" %d",&n);
	int sum = 0;
	int ans = 0;
	int first = 0;
	for(int i = 0; i < n;++i){
		int va;scanf(" %d",&va);
		if(!first && !va)
			continue;
		if(va){
			sum -= 2;
			if(sum >= -1 && sum <= 0)
				ans += (-sum);
			sum = 0;
			++ans;
		}
		if(!va)
			++sum;
		first = 1;
	}
	printf("%d\n",ans);
	return 0;
}