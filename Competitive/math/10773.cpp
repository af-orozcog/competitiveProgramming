#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main(){
	int t;
	scanf(" %d",&t);
	for(int i = 1; i <= t;++i){
		double d,v,u;
		cin >> d >> v >> u;
		double div = v/u;
		if(u == v || v - u > 0.00001 || v == 0.0 || u == 0.0){
			cout << "Case " << i << ": " << "can't determine" << endl;
			continue;
		}
		//cout << div << endl;
		double time1 = d/(cos(asin(div))*u);
		//cout << sin(acos(div)) << endl;
		//cout << time1 << endl;
		double time2 = d/u;
		//cout << time2 << endl;
		cout << "Case " << i << ": " <<setprecision(3) << fixed <<abs(time1-time2) << endl;
	}
	return 0;
}