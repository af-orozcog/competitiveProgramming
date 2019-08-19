#include<iostream>
#include<cmath>
#define ll long long

using namespace std;

int main(){
	int n,m,k;
	scanf(" %d %d %d",&n,&m,&k);
	ll nums[n];
	for(int i = 0; i < n;++i)
		cin >> nums[i];
	ll best = 0;
	ll cum = 0;
	int l = 0;
	for(int i = 0; i < n;++i){
		cum += nums[i]; 
		if(cum < 0){
			cum = 0;
			l = i +1;
			continue;
		}
		double q = i-l+1;
		q = ceil(q/(double)m);
		ll val = cum - (k*q);
		best = max(val,best);
	}
	cout << best << endl;
	return 0;
}