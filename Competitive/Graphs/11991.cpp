/**
* Lo hago por Valentina, para ser mejor y para llegar a Moscú
*/
#include<iostream>
#include<map>
#include<string>
#include<vector>

using namespace std;
typedef vector<int> vi;

int main(){
	int n,q;
	while(cin >> n >> q){
		map<int,vi> occu;
		for(int i = 0; i < n; ++i){
			int val;
			cin >> val;
			occu[val].push_back(i +1);
		}
		while(q--){
			int oc,val;
			cin >> oc >> val;
			if(occu.count(val) == 0){
				cout << 0 << endl;
				continue;
			} 
			vi values = occu[val];
			if(values.size() < oc){
				cout << 0 << endl;
				continue;
			}
			cout << values[oc - 1] << endl;
		}
	}
	return 0;
}