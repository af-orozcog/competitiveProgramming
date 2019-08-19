/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<vector>
#define ll long long
#include<cmath>

using namespace std;

bool intersec(ll *a,ll *b,ll a1,ll b1){
	ll left = max(a1,*a);
	ll right = min(*b,b1);
	if(left > right)
		return false;
	*a = left;
	*b = right;
	return true;
}

int main(){
	int que;
	cin >> que;
	while(que--){
		int ele;
		ll k;
		cin >> ele;
		cin >> k;
		vector<ll> nums(ele);
		ll min = -1;
		ll max = 1000000001;
		bool posi = true;
		for(int i = 0; i < ele;++i){
			cin >> nums[i];
			ll from;
			if(nums[i] <= k)
				from = 1;
			else
				from = nums[i]- k;
			ll to = nums[i] + k;
			if(!intersec(&min,&max,from,to)){
				posi = false;
			}
		}
		if(!posi){
			cout << -1 << endl;
			//cout << "aqui" << endl;
			continue;
		}
		//cout << min << " " << max << endl;
		ll ans = -1;
		for(ll i = max; i >= min;--i){
			bool posi = true;
			for(int j = 0; j < ele;++j){
				//cout << abs(nums[j] - i) << "i es " <<i <<endl;
				if(abs(nums[j] - i) > k){
					posi = false;
					break;
				}
			}
			if(posi){
				ans = i;
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}