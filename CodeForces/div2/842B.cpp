/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<cmath>

using namespace std;

int main(){
	double r,d;
	cin >> r >> d;
	double inr = r - d;
	int cir;
	cin >> cir;
	int insi = 0;
	while(cir--){
		double x,y,ra;
		cin >> x >> y >> ra;
		double imp = (x*x) + (y*y);
		imp = sqrt(imp);
		if(imp > r)
			continue;
		if(imp - inr < 0.0)
			continue;
		double disOut = r - imp;
		double disIn = imp - inr;
		if(disOut < ra)
			continue;
		if(disIn < ra)
			continue;
		++insi;
	}
	cout << insi << endl;
	return 0;
}