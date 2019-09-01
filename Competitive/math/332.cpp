#include<iostream>
#include<string>
#define ll long long

using namespace std;

ll gcd(ll a, ll b){
	return b == 0? a:(gcd(b,a%b));
}

ll power10(ll n){
	ll ans=1;
	for(int i = 0; i<n;++i)
		ans *= 10;
	return ans;
}

int main(){
	ll ca = 0; 
	while(1){
		++ca;
		ll j,m,n;
		scanf(" %lld",&j);
		if(j == -1)
			break;
		string re;
		cin >> re;
		re = re.substr(2,12);
		string rep = "";
		for(int to = re.size()-1-j; to >= 0;--to){
			rep = re[to] + rep;
		}
		if(rep.size() == 0)
			rep = "0";

		pair<ll,ll> ans;
		ans.first = (ll)stoi(re) -(ll)stoi(rep);
		ans.second = power10(re.size()) - power10(re.size()-j);
		printf("Case %lld: %lld/%lld\n",ca,ans.first/gcd(ans.first,ans.second),ans.second/gcd(ans.first,ans.second));
	}
	return 0;
}