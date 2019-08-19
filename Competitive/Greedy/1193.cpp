/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
bool com(const pair<double,double>a, const pair<double,double>b){
	if(a.first < b.first)
		return true;
	if(a.first > b.first)
		return false;
	return a.second > b.second;
}

int main(){
	int cas = 1;
	while(true){
		double is,d;
		cin >> is >> d;
		if(is == 0)
			break;
		vector<pair<double,double>> iland(is);
		bool posi = true;
		for(int i = 0; i < is;++i){
			double val1,val2;
			cin >> val1 >> val2;
			double min = val1 - sqrt(d*d - val2*val2);
			double max = val1 + sqrt(d*d - val2*val2);
			iland[i] = make_pair(min,max);
			if(val2 > d)
				posi = false;
		}
		if(!posi){
			cout << "Case " << cas << ": "<< -1 << endl;
			++cas;
			continue;
		}
		sort(iland.begin(),iland.end(),com);
		pair<double,double> last;
		last = iland[0];
		int total = 1;
		for(int i = 1; i < iland.size();++i){
			while(iland[i].first <= last.second){
				if(iland[i].second < last.second)
					last = iland[i];
				++i;
				if(i == iland.size())
					break;
			}
			if(i == iland.size())
				break;
			++total;
			last = iland[i];
		}
		cout << "Case " << cas << ": "<< total << endl;
		++cas;
	}
	return 0;
}