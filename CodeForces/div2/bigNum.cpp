#include<iostream>
#define ll long long 

using namespace std;
ll difference(ll n){
	ll digits = 0;
	ll copy = n;
	while(copy){
		digits += copy%10;
		copy = copy / 10;
	}
	return n - digits;
}


int main(){
	ll n,s;
	cin >> n >> s;
	if(s >= n){
		cout << 0 << endl;
		return 0; 
	}
	//cout << difference(12) <<endl;
	ll hi = n;
	ll lo = 1;
	ll mid = (lo+hi)/2;
	while(lo <= n){
		//cout << difference(mid) << endl;
		if(difference(mid)>= s){
			//cout << mid << endl;
			if(difference(mid-1) < s)
				break;
			else{
				hi = mid - 1;
				//cout << mid << endl;
			}
		}
		else{
			lo = mid + 1;
		}
		mid = (lo+hi)/2;
		//cout << mid << endl;
	}
	if(lo > n)
		cout << 0 << endl;
	else
		cout << (n - mid) + 1 << endl;
	return 0;
}