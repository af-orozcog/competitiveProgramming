/**
* I'm sorry I was an idiot
*/
#include<iostream>
#include<bitset>
#define ll long long

using namespace std;

int main(){
	int cas;
	cin >> cas;
	while(cas--){
		int dep;
		int bal;
		cin >> dep >> bal;
		--bal;
		--dep;
		ll comp = 2 << dep;
		bitset<20> rep;
		rep.set(dep);
		for(int i = dep -1; i >= 0;--i){
			if(bal){
				if(bal % 2)
					rep.set(i);
			}
			else
				break;
			bal = bal >> 1;
		}
		cout << rep.to_ulong() << endl;
	}
	int ve;
	cin >> ve;
	return 0;
}