/**
* some help this time
*/
#include<iostream>
#include<map>
#define ll long long

using namespace std;

ll gcd(ll a, ll b){
	return b == 0? a : gcd(b,a%b);
}

int main(){
	int n,m;
	scanf(" %d %d",&n,&m);
	ll nums[n];
	ll less[n-1];
	for(int i = 0; i < n;++i)
		cin >> nums[i];
	for(int i = 0; i < n-1;++i)
		less[i] = nums[i+1] - nums[i];
	ll gg = less[0];
	for(int i = 0; i < n-1;++i)
		gg = gcd(gg,less[i]);
	map<ll,int> tr;
	for(int i = 0; i < m;++i){
		ll val;
		cin >> val;
		tr[val] = i;
	}
	for(const auto &pa:tr){
		if(gg % pa.first == 0){
			puts("YES");
			cout << nums[0] << " " << pa.second + 1 << endl;
			return 0;
		}
	}
	puts("NO");
	return 0;
}