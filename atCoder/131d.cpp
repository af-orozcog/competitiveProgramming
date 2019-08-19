/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long

using namespace std;

bool com(const pair<ll,ll> a, const pair<ll,ll> b){
	if(a.second < b.second)
		return true;
	if(a.second > b.second)
		return false;
	return a.first > b.first;
}

int main(){
	int j;
	cin >> j;
	vector<pair<ll,ll>> jobs(j);
	for(int i = 0; i < j;++i){
		ll val1,val2;
		cin >> val1 >> val2;
		jobs[i] = make_pair(val1,val2);
	}
	sort(jobs.begin(),jobs.end(),com);
	ll current = 0;
	bool posi = true;
	for(int i = 0; i < j;++i){
		if(current + jobs[i].first > jobs[i].second){
			posi = false;
			break;
		}
		current += jobs[i].first;
	}
	if(posi)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}