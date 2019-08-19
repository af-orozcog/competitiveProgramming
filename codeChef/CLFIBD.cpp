/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	int cas;
	cin >> cas;
	while(cas--){
		string toCheck;
		cin >> toCheck;
		if(toCheck.size() < 3){
			cout << "Dynamic" << endl;
			continue;
		}
		map<char,int> unique;
		for(int i = 0; i < toCheck.size();++i){
			if(unique.count(toCheck[i]) > 0)
				++unique[toCheck[i]];
			else
				unique[toCheck[i]] = 1;
		}
		vector<int> per;
		for(const auto &pa: unique){
			per.push_back(pa.second);
		}
		sort(per.begin(),per.end());
		bool posi = true; 
		for(int i = 2; i < per.size();++i){
			int a = per[i-2];
			int b = per[i-1];
			if(a + b != per[i]){
				posi = false;
				break;
			}
		}
		if(!posi){
			int temp = per[0];
			per[0] = per[1];
			per[1] = temp;
			posi = true;
			for(int i = 2; i < per.size();++i){
				int a = per[i-2];
				int b = per[i-1];
				if(a + b != per[i]){
					posi = false;
					break;
				}
			}
		}
		if(posi)
			cout << "Dynamic" << endl;
		else
			cout << "Not" << endl;
	}
	return 0;
}