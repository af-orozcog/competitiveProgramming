#include<iostream>
#define ER 1e-7
#include<cmath>
#include<vector>

using namespace std;

vector<pair<double,double>> pl;
double ini;

bool simul(double x){
	double tot = ini + x;
	double cost = tot / pl[0].first;
	tot -= cost;
	x -= cost;
	for(int i = 1; i < pl.size();++i){
		if(x < 0)
			return false;
		cost = tot / pl[i].second;
		tot -= cost;
		x -= cost;
		if(x < 0)
			return false;
		cost = tot / pl[i].first;
		tot -= cost;
		x -= cost;
	}
	cost = tot / pl[0].second;
	tot -= cost;
	x -= cost;
	if(x < 0)
		return false;
	return true;
}

int main(){
	int N;
	cin >> N;
	cin >> ini;
	for(int i = 0; i < N;++i){
		double a;
		cin >> a;
		pl.push_back(make_pair(a,0.0));
	}
	for(int i = 0; i < N;++i){
		double a;
		cin >> a;
		pl[i].second = a;
	}
	double lo = 1.0, hi =1000000000.0;
	double ans = -1;
	while(abs(lo-hi) > ER){
		double mid = (lo+hi)/2.0;
		if(simul(mid)){
			ans = mid;
			hi = mid;
		}
		else
			lo = mid;
	}
	cout << ans << endl;
}