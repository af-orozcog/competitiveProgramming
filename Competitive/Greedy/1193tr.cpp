/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
bool com(const pair<double,double>a, const pair<double,double>b){
	if(a.second > b.second)
		return true;
	else if(a.second < b.second)
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
			iland[i] = make_pair(val1,val2);
			if(val2 > d)
				posi = false;
		}
		if(!posi){
			cout << "Case " << cas << ": "<< -1 << endl;
			++cas;
			continue;
		}
		sort(iland.begin(),iland.end(),com);
		double last;
		for(double i = d; i >= 0.0; --i){
			double maxDis = sqrt((d*d)-(i*i));
			maxDis = trunc(maxDis);
			if(maxDis >= iland[0].second){
				last = iland[0].first + i;
				break;
			}
		}
		//cout << last << endl;
		int total = 1;
		for(int i = 1; i < iland.size();++i){
			double dis = abs(last - iland[i].first);
			dis = dis * dis;
			dis += (iland[i].second * iland[i].second);
			dis = sqrt(dis);
			if(dis > d){
				++total;
				cout << "last: " << last << " not work: "<< iland[i].first << " " << iland[i].second << endl;
				for(double j = d; j >= 0.0; --j){
					double maxDis = sqrt((d*d)-(j*j));
					maxDis = trunc(maxDis);
					if(maxDis >= iland[i].second){
						last = iland[i].first + j;
						break;
					}
				}
			}
		}
		cout << "Case " << cas << ": "<< total << endl;
		++cas;
	}
	return 0;
}