/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<cstring>
#include<string>
#include<climits>
#define ll long long

using namespace std;

ll min(ll x,ll y){
	if(x < y)
		return x;
	return y;
}
ll max(ll x,ll y){
	if(x > y) return x;
	return y;
}
int N;
ll memo[1000][8];
pair<ll,ll> jui[1000];
ll solve(int toTake,ll took){
	if(took == 7)
		return 0;
	if(toTake == N && took == 7)
		return 0;
	if(toTake == N)
		return LLONG_MIN;
	if(memo[toTake][took] != -1)
		return memo[toTake][took];
	ll tookNew = took | jui[toTake].second;
	ll one = jui[toTake].first + solve(toTake+1,tookNew);
	ll two = solve(toTake+1,took);
	if(one < 0 || two < 0)
		return memo[toTake][took] = max(one,two);
	return memo[toTake][took] = min(one,two);
}

int main(){
	cin >> N;
	memset(memo,-1,sizeof(memo));
	for(int i = 0; i < N;++i){
		int val;
		string vit;
		cin >> val; 
		cin >> vit;
		int add = 0;
		for(int j = 0; j < vit.size();++j){
			if(vit[j] == 'A')
				add = add | (1 << 2);
			else if(vit[j] == 'B')
				add = add | (1<<1);
			else
				add = add | (1);
		}
		jui[i] = make_pair(val,add);
	}
	ll ans = solve(0,0);
	if(ans < 0)
		cout << -1 << endl;
	else
		cout << ans << endl;
	return 0;
}