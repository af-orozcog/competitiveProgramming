/**
* ALL I DO IS WRONG
*/
#include<bits/stdc++.h>
#define ll long long

using namespace std;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
typedef vector<vector<pii>> vpii;
int freq[26];

int main(){
	string re;
	cin >> re;
	for(int i = 0; i < re.size();++i)
		++freq[re[i]-'a'];
	vector<pair<int,int>> imp;
	vector<pair<int,int>> pa;
	for(int i = 0; i < 26;++i){
		if(freq[i]%2)
			imp.push_back({i,freq[i]});
		else
			pa.push_back({i,freq[i]});
	}
	int i = 0,j = imp.size()-1;
	while(i < j){
		++imp[i].second;
		--imp[j].second;
		pa.push_back(imp[i]);
		pa.push_back(imp[j]);
		++i;--j;
	}
	if(i == j){
		--imp[i].second; 
		pa.push_back(imp[i]);
		imp[i].second = 1;
	}
	string va = "";
	sort(pa.begin(),pa.end());
	for(int i = 0; i < pa.size();++i){
		for(int j = 0; j < (pa[i].second>>1);++j)
			va+= (pa[i].first+'a');
	}
	if(i == j)
		va+=(imp[i].first+'a');
	for(int i = pa.size()-1; i >-1;--i){
		for(int j = 0; j < (pa[i].second>>1);++j)
			va+= (pa[i].first+'a');
	}
	cout << va << endl;
	return 0;
}