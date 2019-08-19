/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#define min(x,y)(x < y?x:y)
#define ll long long

using namespace std;

bool com(const pair<ll,ll> a, const pair<ll,ll> b){
	if(a.second < b.second)
		return true;
	if(a.second > b.second)
		return false;
	return a.first < b.first;
}

int main(){
	int n,m;
	cin >> n >>m;
	map<ll,pair<ll,ll>> inn;
	vector<pair<ll,ll>> nums(n);
	for(int i = 0; i < n;++i){
		nums[i].first = i;
		ll val;
		cin >> val;
		inn[i] = make_pair(val,0);
	}
	for(int i = 0; i < n;++i){
		ll val;
		cin >> val;
		inn[i].second = val;
		nums[i].second = val;
	}
	bool posi = true;
	sort(nums.begin(),nums.end(),com);
	int at = 0;
	for(int i = 0; i < m;++i){
		ll f,w;
		cin >> f >> w;
		ll toAdd = 0;
		f--;
		while(w && posi){
			if(inn[f].first > 0){
				ll le = min(inn[f].first,w);
				toAdd += le*inn[f].second;
				inn[f].first -= le;
				w -= le;
			}
			else{
				while(inn[nums[at].first].first == 0 && at < n){++at;}
				if(at == n){
					toAdd = 0;
					posi = false;
					break;
				}
				//cout << at << endl;
				ll le = min(inn[nums[at].first].first,w);
				toAdd += le*inn[nums[at].first].second;
				inn[nums[at].first].first -= le;
				w -= le;
			}
		}
		cout << toAdd << endl;
	}
}