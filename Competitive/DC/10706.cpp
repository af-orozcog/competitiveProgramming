/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<cmath>
#define ll long long

using namespace std;

int main(){
	vector<ll> inter ={0};
	string nums = "";
	ll i = 1;
	ll coun = 1;
	ll toLen = 0;
	for(int i = 1; i < 33000; ++i){
		nums += to_string(i);
		int len = (int)log10(i)+1;
		toLen += len;
		inter.push_back(toLen + inter[i-1]);
	}
	int cas;
	cin >> cas;
	while(cas--){
		ll val;
		cin >> val;
		vector<ll>::iterator low = lower_bound(inter.begin(),inter.end(),val);
		ll ind = low - inter.begin();
		if(low == inter.end())
			--ind;
		if(inter[ind] >= val)
			--ind;
		//cout << inter[ind] << endl;
		//cout << "el indice es: " << ind << endl;
		//cout << val - inter[ind] - 1 << endl;
		cout << nums[val - inter[ind] - 1] << endl;
	}
	return 0;
}