#include<iostream>
#include<queue>
#include<cmath>
#define ll long long

using namespace std;

int main(){
	ll n, k;
	cin >> n >> k;
	ll vals[n];
	for(int i = 0; i < n;++i) cin >> vals[i];
	ll add;
	cin >> add;
	ll costs[n];
	for(int i = 0; i < n;++i) cin >> costs[i];
	ll needed = 0;
	ll ans = 0;
	priority_queue<ll> pq;
	bool posi = true;
	for(int i = 0; i < n && posi;++i){
		pq.push(-costs[i]);
		ll ne = ceil((double)(vals[i]-k)/(double)add);
		//cout << ne << endl;
		if(ne > needed){
			for(;needed < ne && posi;++needed){
				if(pq.size() != 0)
					ans += (-pq.top());
				else{
					posi = false;
					break;
				}
				pq.pop();
			}
		}
	}
	if(posi)
		cout << ans << endl;
	else
		cout << "-1" << endl;
	return 0;
}