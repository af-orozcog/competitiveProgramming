/**
* I'm sorry I was an idiot
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
	int cas;
	scanf(" %d",&cas);
	bool first = true;
	while(cas--){
		if(!first)
			cout << endl;
		first = false;
		vector<pair<int,int>> pa;
		int m;
		scanf(" %d",&m);
		int l,r;
		while(scanf(" %d %d",&l,&r) && (l || r)){
			pa.push_back(make_pair(l,r));
		}
		sort(pa.begin(),pa.end(),com);
		int sta = -1;
		pair<int,int> last = make_pair(-40,-39);
		for(int i = 0; i < pa.size();++i){
			if(pa[i].first > 0)
				break;
			if(last.first == -40 && last.second == -39 
				&& pa[i].first <= 0 
				&& pa[i].second >= 0){
				last = pa[i];
				sta = i;
			}
			else if(pa[i].first > last.first && pa[i].second > last.second){
				if(pa[i].first <= 0 && pa[i].second >= 0){
					sta = i;
					last = pa[i];
				}
			}
		}
		if(sta == -1){
			cout << 0 << endl;
			continue;
		}
		vector<pair<int,int>> ans = {pa[sta]};
		++sta;
		bool posi = true;
		if(sta == pa.size()){
			//cout << "?" << endl;
			if(last.first <= 0 && last.second >= m){
				posi = true;
				//cout << last.first << " " << last.second << " " << m << " " ;
			}
			else 
				posi = false;
		}
		/**for(int i = 0; i < pa.size();++i){
			cout << pa[i].first << "-" << pa[i].second << " ";
		}
		cout << endl;*/
		//cout << last.first << " " << last.second << endl;
		while(last.second < m && sta < pa.size()){
			if(last.second >= pa[sta].second){
				//cout << last.first << " " << last.second << endl;
				//cout << "other: " << pa[sta].first << " " << pa[sta].second << endl;
				++sta;
				continue;
			}
			else if(sta != pa.size() - 1 && last.second < pa[sta+1].first){
				if(last.second >= pa[sta].first){
					last = pa[sta];
					ans.push_back(last);
					++sta;
				}
				else{
					//cout << "aqui?" << endl;
					posi = false;
					break;
				}
			}
			else{
				//cout << "aqui? " << endl;
				if(sta == pa.size() - 1 &&
					last.second >= pa[sta].first
					&& pa[sta].second >= m){
					ans.push_back(pa[sta]);
					break;
				}
				if(last.second < pa[sta].first){
					posi = false;
					break;
				}
				if(last.second >= pa[sta+1].first && pa[sta].second < pa[sta+1].second){
					++sta;
					continue;
				}
				int com = sta + 1;
				while(com < pa.size()){
					if(last.second < pa[com].first){
						last = pa[sta];
						ans.push_back(last);
						sta = com;
						break;
					}
					if(last.second >= pa[com].first && pa[sta].second < pa[com].second){
						sta = com;
						break;
					}
					++com;
				}
				if(com == pa.size()){
					ans.push_back(pa[sta]);
					break;
				}
			}
		}
		if(!posi || ans[ans.size()-1].second < m){
			cout << 0 << endl;
			continue;
		}
		//cout << "sta es: " << endl;
		cout << ans.size() << endl;
		for(int i = 0; i < ans.size();++i){
			cout << ans[i].first << " " << ans[i].second << endl;
		}
	}
	return 0;
}