#include<iostream>
#define ll long long
#include<vector>
#include<algorithm>

using namespace std;

bool com(const pair<ll,ll> a, const pair<ll,ll> b){
	return a.second < b.second;
}
bool posi(vector<pair<ll,ll>> &vals,int except){
	if(vals.size() == 2 || vals.size() == 3)
		return true;
	for(int i = 0; i < vals.size() -2;++i){
		if(i == except){
			continue;
		}
		else if(i + 1 == except){
			if(i + 3 < vals.size()){
				if(vals[i+2].second - vals[i].second != vals[i+3].second - vals[i+2].second)
					return false;
			}
			else{
				if(i + 2 == vals.size())
					return true;
				else{
					if(vals[i+2].second - vals[i].second != vals[i].second - vals[i-1].second)
						return false;
				}
			}
		}
		else if(vals[i+2].second - vals[i+1].second != vals[i+1].second - vals[i].second)
			return false;
	}
	return true;
}

int main(){
	int siz;
	cin >> siz;
	vector<pair<ll,ll>> nums(siz);
	for(ll i = 0; i < siz;++i){
		ll val;
		cin >> val;
		nums[i] = make_pair(i,val);
	}
	sort(nums.begin(),nums.end(),com);
	int i = 0;
	for(; i < nums.size() - 1;++i){
		if(posi(nums,i)){
			break;
		}
	}
	if(i == nums.size())
		cout << -1 << endl;
	else
		cout << nums[i].second << endl;
	return 0;
}
