/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;

ll gcd(ll a, ll b){
	return b == 0 ? a : gcd(b,a%b); 
}

vector<ll> divisors(ll n){
	ll to = sqrt(n);
	vector<ll> answer;
	for(ll i = 1; i <= to;++i){
		if(n % i == 0){
			answer.push_back(i);
			if(n/i != i)
				answer.push_back(n/i);
		}
	}
	sort(answer.begin(),answer.end());
	return answer;
}

int main(){
	ll va1,va2;
	cin >> va1 >> va2;
	ll imp = gcd(va1,va2);
	vector<ll> div = divisors(imp);
	int que;
	cin >> que;
	while(que--){
		ll lo,hi;
		cin >> lo >> hi;
		vector<ll>::iterator low = lower_bound(div.begin(),div.end(),hi);
		ll index = low - div.begin();
		if(low == div.end())
			--index;
		if(hi > imp){
			if(div[index] >= lo){
				cout << div[index] << endl;
				continue;
			}
		}
		if(div[index] == hi){
			cout << hi << endl;
			continue;
		}
		--index;
		if(div[index] < hi && div[index] >= lo)
			cout << div[index] << endl;
		else
			cout << -1 << endl;
	}
	return 0;
}