/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
bool com(const pair<double,double> a, const pair<double,double> b){
	if(a.first < b.first)
		return true;
	if(a.first > b.first)
		return false;
	return a.second < b.second;
}

int main(){
	double n,l,w;
	while(cin >> n >> l >> w){
		vector<pair<double,double>> ranges((int)n);
		for(int i = 0; i < n;++i){
			double pos,ra;
			cin >> pos >> ra;
			double impo = ra*ra - (w*w/4.0);
			if(impo <= 0)
				ranges[i] = make_pair(0,0);
			else{
				impo = sqrt(impo);
				ranges[i] = make_pair(pos-impo,pos+impo);
			}
		}
		sort(ranges.begin(),ranges.end(),com);
		int sta = -1;
		pair<double,double> last;
		for(int i = 0; i < ranges.size();++i){
			if(ranges[i].first > 0)
				break;
			if(sta == -1 && ranges[i].first <= 0
				&& ranges[i].second >= 0){
				sta = i;
				last = ranges[i];
			}
			else if(sta != -1 && ranges[i].second > last.second){
				sta = i;
				last = ranges[i];
			}
		}
		if(sta == -1){
			cout << -1 << "\n";
			continue;
		}
		bool posi = true;
		int total = 1;
		++sta;
		while(sta < ranges.size() && last.second < l){
			if(last.second >= ranges[sta].second){
				++sta;
			}
			else if(sta != ranges.size() -1 && last.second < ranges[sta+1].first){
				if(last.second >= ranges[sta].first){
					last = ranges[sta];
					++total;
					++sta;
				}
				else{
					posi = false;
					break;
				}
			}
			else{
				if(sta == ranges.size()-1 &&
					ranges[sta].first <= last.second &&
					ranges[sta].second >= l){
					last = ranges[sta];
					++total;
					break;
				}
				else if(sta != ranges.size()-1 &&
					last.second >= ranges[sta+1].first
					&& ranges[sta].second < ranges[sta+1].second){
					++sta;
					continue;
				}
				int com = sta + 1;
				while(com < ranges.size()){
					if(last.second < ranges[com].first){
						last = ranges[sta];
						sta = com;
						++total;
						break;
					}
					else if(last.second >= ranges[com].first
					&& ranges[sta].second < ranges[com].second){
						sta = com;
						break;
					}
					++com;
				}
				if(com == ranges.size()){
					last = ranges[sta];
					++total;
					break;	
				}
			}
		}
		if(!posi || last.second < l){
			cout << -1 << "\n";
			continue;
		}
		else
			cout << total << "\n";
	}
	return 0;
}