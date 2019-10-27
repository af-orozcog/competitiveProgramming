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

int leftMost(ll val){
	int i = 0;
	while(val){
		val = val >> 1;
		++i;
	}
	return i;
}

int canK(ll num, int k){
	priority_queue<ll> nums;
	int i = 0;
	ll shi = 1;
	while(num){
		if(num&1)
			nums.push(shi<<i);
		num = num >>1;
		++i;
	}
	while((int)nums.size() < k && nums.top() != 1){
		ll va = nums.top();
		nums.pop();
		nums.push(va>>1);
		nums.push(va>>1);
	}
	return (int)nums.size() == k;
}

int main(){
	ll n,p;
	cin >> n >> p;
	int i = 0;
	if(p < 0){
		int ans = 0;
		while(1 && ans != -1){
			n -= p;
			++i;
			int le = leftMost(n);
			if(le < i)
				ans = -1;
			else{
				if(canK(n,i)){
					ans = i;
					break;
				}
			}
		}
		printf("%d\n",ans);
	}
	else if(p > 0){
		int ans = 0;
		while(n >= 0 && ans != -1){
			n -= p;
			++i;
			int le = leftMost(n);
			if(le < i)
				ans = -1;
			else{
				if(canK(n,i)){
					ans = i;
					break;
				}
			}
		}
		printf("%d\n",ans);
	}
	else{
		int ans = 0;
		while(n){
			if(n&1)
				++ans;
			n = n >> 1;
		}
		printf("%d\n",ans);
	}
	return 0;
}