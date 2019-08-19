/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#define ll long long

using namespace std;
int main(){
	ll n,m,k;
	cin >> n >>m>>k;
	vector<ll> ar(m);
	for(int i = 0; i < m;++i){
		cin >>ar[i];
	}
	ll l = 0;
	ll mul = ceil((double)ar[0]/(double)k);
	ll tot = 0;
	ll last = 0;
	while(1){
		ll look = (mul * k)+l;
		int index = lower_bound(ar.begin(),ar.end(),look) - ar.begin();
		//cout << "look " <<look <<" index "<< index<<endl;
		if(index == ar.size()){
		    ++tot;
			break;
		}
		//cout << " l es "<<l << endl;
		++tot;
		l += index - last;
		if(ar[index] == look){
			l++;
			index++;
		//	cout << "entro aqui "<<endl;
			if(index == ar.size())
			    break;
			//break;
		}
		last = index;
		mul = ceil((double)(ar[index]-l)/(double)k);
	}
	cout << tot << endl;
	return 0;
}