#include<stdio.h>
#include<iostream>
#include<cmath>
#define EPS 1e-9

using namespace std;
int p,q,r,s,t,u;

double solution(double val){
	double ans = p * exp(-val);
	ans += q*sin(val);
	ans += r * cos(val);
	ans += s * tan(val);
	ans += t*(val*val);
	ans += u;
	return ans;
}

int main(){
	while(cin >> p >> q >> r >> s >> t >> u){
		double lo = 0.0,hi = 1.0, ans = -1.0, last = fabs(solution(1));
		cout << last << endl;
		last = fabs(last);
		//bool down;
		while(abs(lo-hi) > EPS){
			double mid = (hi+lo) /2.0;
			double sol = solution(mid);
			cout << sol << " mid es: "<< mid<<endl;
			if(fabs(sol) <= EPS){
				ans = mid;
				break;
			}
			if(fabs(solution(mid+ (mid/2.0))) < fabs(solution(mid -(mid/2.0)))){
				lo = mid;
				last = fabs(solution(mid+ (mid/2.0)));
			//	down = false;
			}
			else{
				hi = mid;
				last = fabs(solution(mid -(mid/2.0)));
			//	down = true;
			}
			//cout << mid << endl;
		}
		if(ans == -1.0)
			cout << "No solution" << endl;
		else{
			printf("%.4f\n",solution(ans));
		}
	}
	return 0;
}