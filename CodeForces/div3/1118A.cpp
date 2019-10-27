/**
* ALL I DO IS WRONG
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
	ll sum1[n+1];
	ll sum2[n+1];
	sum1[0] = sum2[0] = 0;
	for(int i = 1; i <= n;++i){
		ll va;cin >> va;
		sum1[i] = sum1[i-1];
		sum2[i] = sum2[i-1];
		if(i & 1)
			sum1[i] += va;
		else
			sum2[i] += va;
	} 
	ll ans = 0;
	for(int i = 1; i <= n;++i){
		if(i & 1){
			int impa = sum1[i-1] + (sum2[n]-sum2[i-1]);
			int pa = sum2[i-1] + (sum1[n]-sum1[i]);
			if(impa == pa)
				++ans;
		}
		else{
			int impa = sum1[i-1] + (sum2[n]-sum2[i]);
			int pa = sum2[i-1] + (sum1[n]-sum1[i-1]);
			if(impa == pa)
				++ans;	
		}
	}
	cout << ans << endl;
	return 0;
}