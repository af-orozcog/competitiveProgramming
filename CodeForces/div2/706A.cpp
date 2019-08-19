#include<iostream>
#include<cmath>

using namespace std;

double dist(double a,double b, double c, double d){
	return sqrt((a-c)*(a-c) + (b-d)*(b-d));
}

int main(){
	double a,b;
	cin >> a >> b;
	int n;
	cin >> n;
	double min = 100000000.0;
	while(n--){
		double c,d,s;
		cin >> c >> d >> s;
		double  val = dist(a,b,c,d) /s;
		if(val - min < 0.0)
			min = val;
	}
	printf("%.08f\n",min);
	return 0;
}