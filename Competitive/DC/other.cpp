#include<stdio.h>
#include<iostream>
#include<cmath>
#define EPS 1e-8

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
		double lo = 0.0,hi = 1.0, ans = -1.0, last = solution(1.0);
		//cout << "pasa aqui" << endl;
		bool down = true;
		while(abs(lo-hi) > EPS){
			double mid = (hi+lo) /2.0;
			double sol = solution(mid);
			cout << sol << endl;
			if(abs(sol) <= EPS){
				ans = mid;
				break;
			}
			else if(sol < last){
				if(down){
					hi = mid;
				}
				else{
					lo = mid;
					down = false;
				}
			}
			else{
				if(down){
					lo = mid;
					down = false;
				}
				else{
					hi = mid;
					down = true;
				}
			}
			last = sol;
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