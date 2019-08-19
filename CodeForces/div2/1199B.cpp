/**
* about to get grey
*/
#include<iostream>

using namespace std;

int main(){
	double h,l;
	cin >> h >> l;
	double h2,l2;
	h2 = h*h;
	l2 = l*l;
	h2 = -h2;
	l2 = -l2;
	//cout << h2 << endl;
	//cout << l2 << endl;
	double ans = (h2 + l2)/(-2*h);
	ans -= h;
	printf("%.15f\n",ans);
	return 0;
}