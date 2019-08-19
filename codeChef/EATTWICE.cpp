/**
* I'm sorry I was an idiot
*/
#include<iostream>
#include<map>
#include<cmath>
#define ll long long

using namespace std;

int main(){
	int cas;
	cin >> cas;
	while(cas--){
		map<int,ll> maxVals;
		int N,M;
		cin >> N >> M;
		while(N--){
			ll day,val;
			cin >> day >> val;
			if(maxVals.count(day) == 0)
				maxVals[day] = val;
			else
				maxVals[day] = max(maxVals[day],val);
		}
		int max1 = -1;
		int max2 = -1;
		for(const auto &pa: maxVals){
			if(pa.second > max1){
				max2 = max1;
				max1 = pa.second;
			}
			else if(pa.second > max2){
				max2 = pa.second;
			}
		}
		cout << max1 + max2 << endl;
	}
	return 0;
}