#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int n;
	scanf(" %d",&n);
	ll ans = 0;
	vector<ll> sml(1000001,0);
	vector<ll> big(1000001,0);
	ll special = 0;
	for(int i = 0;i < n;++i){
		int j;scanf(" %d",&j);
		int mi = 10000001,bi = -1;
		bool va = 0;
		for(int k = 0;k < j;++k){
			int re; scanf(" %d",&re);
			if(re > mi) va=1;
			mi = min(mi,re); bi = max(bi,re);
		}
		if(va) ++special;
		else{
			++sml[mi];
			++big[bi];
		}
	}
    ans += special;
    for(int i = 1; i <= special;++i)
        ans += ((n-i)<<1);
	for(int i = 1;i < sml.size();++i)
		sml[i] += sml[i-1];
	for(int i = big.size()-1;i > 0;--i)
		ans += big[i]*sml[i-1];
	cout << ans << endl;
	return 0;
}
