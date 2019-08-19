/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool com(const pair<int,int> a, const pair<int,int> b){
	if(a.first < b.first)
		return true;
	if(a.first > b.first)
		return false;
	return a.second > b.second;
}

int main(){
	while(true){
		int l,n;
		cin >> l >> n;
		if(l == 0)
			break;
		vector<pair<int,int>> inter(n);
		for(int i = 0; i < n;++i){
			int val1,val2;
			cin >> val1 >> val2;
			inter[i] = make_pair(val1 - val2,val1 + val2);
		}
		sort(inter.begin(),inter.end(),com);
		int sta = -1;
		pair<int,int> last;
		for(int i = 0; i < n;++i){
			if(inter[i].first > 0)
				break;
			else if(sta == -1){
				sta = i;
				last = inter[i];
			}
			else if(sta != -1 && inter[i].second > last.second){
				sta = i;
				last = inter[i];
			}
		}
		if(sta == -1){
			cout << -1 << endl;
			continue;
		}
		int total = 1;
		while(last.second < l && sta < inter.size()){
			if(sta == inter.size() - 1){
				if(inter[sta].first > last.second){
					last = make_pair(0,l-1);
					break;
				}
				++total;
				last = inter[sta];
				break;
			}
			else if(last.second >= inter[sta].second){
				++sta;
				continue;
			}
			else if(last.second < inter[sta+1].first){
				if(last.second >= inter[sta].first){
					++total;
					last = inter[sta];
					++sta;
				}
				else
					break;
			}
			else{
				if(last.second >= inter[sta+1].first && 
					inter[sta + 1].second >= inter[sta].second){
					++sta;
					continue;
				}
				int com = sta + 1;
				while(com < inter.size()){
					if(last.second < inter[com].first){
						last = inter[sta];
						++total;
						sta = com;
						break;
					}
					if(last.second >= inter[com].first &&
						inter[com].second >= inter[sta].second){
						sta = com;
						break;
					}
					++com;
				}
				if(com == inter.size()){
					++total;
					last = inter[sta];
					break;
				}
			}
		}
		if(last.second < l){
			cout << -1 << endl;
			continue;
		}
		cout << inter.size() - total << endl;
	}
	return 0;
}