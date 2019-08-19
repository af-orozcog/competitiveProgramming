/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long

using namespace std;

ll swaps(vector<pair<ll,int>> &vec, int less, int more, int targ){
	int lo = 0,hi = vec.size()-1;
	int nedM = 0;
	int nedL = 0;
	int nedMT = 0;
	int nedLT = 0;
	while(lo <= hi){
		int mid = (lo+hi) >> 1;
		if(mid < targ){
			if(vec[mid].first > vec[targ].first)
				++nedL;
			lo = mid + 1;
			++nedLT;
		}
		else if(mid > targ){
			if(vec[mid].first < vec[targ].first)
				++nedM;
			hi = mid - 1;
			++nedMT;
		}
		else
			break;
		//cout << "aqui" << endl;
	}
	if(nedMT > more || nedLT > less)
		return -1;
	int max;
	if(nedM > nedL)
		max = nedM;
	else
		max = nedL;
	return max;
}

bool com(const pair<ll,int> a, const pair<ll,int> b){
	return a.first < b.first;
}
int main(){
	int cas;
	cin >> cas;
	while(cas--){
		int siz,stud;
		cin >> siz >> stud;
		vector<pair<ll,int>> nums(siz);
		for(int i = 0; i < siz;++i){
			ll val;
			cin >> val;
			nums[i] = make_pair(val,i);
		}
		vector<pair<ll,int>> copy = nums;
		sort(copy.begin(),copy.end(),com);
		while(stud--){
			ll toSee;
			cin >> toSee;
			pair<ll,int> a;
			a.first = toSee;
			a.second = 0;
			vector<pair<ll,int>>::iterator low = lower_bound(copy.begin(),copy.end(),a,com);
			int less = low - copy.begin();
			int more = copy.size() - (less + 1);
			cout << swaps(nums,less,more,copy[less].second) << endl;; 
		}
	}
}