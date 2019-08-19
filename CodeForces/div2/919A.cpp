#include<iostream>

using namespace std;

int main(){
	double min = 10000000.0;
	int n;
	double m;
	cin >> n >>m;
	while(n--){
		double a,b;
		cin >> a >> b;
		double val = (a/b)*m;
		//cout << val << endl;
		if(val- min < 0.0)
			min = val;
	}
	printf("%.08f\n",min);
	return 0;
}