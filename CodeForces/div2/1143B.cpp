#include<iostream>
#define ll long long
#include<algorithm>
#include<vector>
#define max(x,y)(x > y? x:y)

using namespace std;

ll pow(ll a, ll b){
	ll ans = 1;
	for(int i = 0; i< b;++i)
		ans *= a;
	return ans;
}

vector<int> digits(ll n){
	vector<int> ans;
	while(n){
		ans.push_back(n%10);
		n /= 10;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}
ll solve(int p,vector<int> &digi){
	if(p == digi.size())
		return 1;
	ll val = digi[p] * solve(p+1,digi);
	if(digi[p] == 0)
		return 0;
	if(digi[p] == 1)
		val = max(val,pow(9,digi.size()-(p+1)));
	else
		val = max(val,pow(9,digi.size()-(p+1))*(digi[p]-1));
	return val;
}

int main(){
	ll val;
	cin >> val;
	vector<int> digi = digits(val);
	cout << solve(0,digi) << endl;
}