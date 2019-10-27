#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<string>
#define ll long long

using namespace std;

ll cummu[26];
int main(){
	int n;
	scanf(" %d",&n);
	unordered_map<char,unordered_set<string>> fr;
	unordered_map<string,ll> que;
	while(n--){
		string name;
		cin >> name;
		fr[name[0]].insert(name);
		if(que.count(name))
			++que[name];
		else
			que[name] = 1;
		++cummu[name[0] -'A'];
	}
	ll ans = 0;
	for(auto &va:fr){
		for(auto i = va.second.begin(); i != va.second.end();++i){
			auto co = i;
			//cout << (*i) << endl;
			//cout << cummu[(*i)[0]-'A'] << endl;
			ll num1 = que[(*i)];
			ans += (cummu[(*i)[0]-'A']-num1)*num1;
		}
	}
	cout << ans << endl;
	return 0;
}