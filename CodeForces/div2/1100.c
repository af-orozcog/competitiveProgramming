#include<stdio.h>
#define INF 1e-5
#include<math.h>
#define abs(x)(x < 0? -x:x)
#define PI 3.14159265358979323846

int main(){
	double n,r;
	scanf("%lf %lf",&n,&r);
	double hi = r*20000;
	double lo = 0;
	double com1;
	double com2 = 1.0/(sin(2*PI/n));
	double nSlope = com2;
	double nece = sin(2*PI/n);
	com2 = -1.0/(com2);
	double ans;
	while(fabs(lo - hi) > INF){
		double mid = (hi+lo)/2.0;
		double
		printf("com: %lf check: %lf\n",com,check);
		if(abs(check-com) <= INF){
			ans = mid - r;
		}
		else if(com - check < 0)
			hi = mid;
		else
			lo = mid;
	}
	printf("%lf\n",ans);
}