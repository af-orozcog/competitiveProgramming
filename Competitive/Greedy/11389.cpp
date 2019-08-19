/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool com(const int a, const int b){
	return a > b;
}

int main(){
	int n,d,r;
	while(cin >> n >> d >> r){
		if(n == 0)
			break;
		vector<int> night(n);
		vector<int> day(n);
		for(int i = 0; i < n;++i){
			cin >> day[i];
		}
		for(int i = 0; i < n;++i){
			cin >> night[i];
		}
		sort(night.begin(),night.end(),com);
		sort(day.begin(),day.end());
		int total = 0;
		for(int i = 0; i < n;++i){
			int val = day[i] + night[i];
			int toAdd = val - d;
			if(toAdd > 0){
				total += toAdd * r;
			}
		}
		cout << total << endl;
	}
	return 0;
}