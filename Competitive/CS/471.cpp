/**
* I'm an idiot
*/
#include<iostream>
#include<bitset>
#define ll long long

using namespace std;
bool unique(ll val){
	bitset<10> vals;
	while(val){
		if(vals[val%10])
			return false;
		vals.set(val%10);
		val /= 10;
	}
	return true;
}

int main(){
	int cas;
	cin >> cas;
	bool first = true;
	while(cas--){
		if(!first)
			cout << endl;
		ll val;
		cin >> val;
		int i = 1;
		while(true){
			if(!unique(i)){
				++i;
				continue;
			}
			ll toSee = i *val;
			if(toSee >= 10000000000)
				break;
			if(unique(toSee)){
				cout << toSee << " / " << i << " = " << val << endl;
			}
			++i;
		}
		first = false;
	}
	return 0;
}