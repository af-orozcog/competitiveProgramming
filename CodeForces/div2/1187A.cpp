/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#define ll long long
#define min(x,y)(x < y ? x:y)
#define max(x,y)(x > y ? x:y)

using namespace std;

int main(){
	int cas;
	cin >> cas;
	while(cas--){
		ll n,s,t;
		cin >> n >> s >> t;
		if(n == s && n == t){
			cout << 1 << endl;
			continue;
		}
		ll less = s + t;
		less = less - n;
		s -= less;
		t -= less;
		ll ans = max(s,t);
		cout << ans + 1 << endl;
	}
	return 0;
}