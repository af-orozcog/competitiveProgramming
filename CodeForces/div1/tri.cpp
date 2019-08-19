#include<iostream>
#include<cmath>

using namespace std;
bool isInt(double n){
	int m = n;
	return n - (double)m == 0;
}

int main(){
	double a,b;
	cin >> a >> b;
	double x1 = 0;
	double y1 = 0;
	double x2;
	double y2;
	double x3;
	double y3;
	double hyp = sqrt((a*a) + (b*b));
	int times = 0;
	while(times < 2){
		for(double i = -a; i <= a; i++){
			double ytry;
			if(times == 0)
				ytry = asqrt((a*a) - (i*i));
			else
				ytry = -sqrt(((a*a) - (i*i)));
			if(isInt(ytry) && x1 != i && y1 != ytry){
				int times2;
				while(times2 < 2){
					for(double j = i - hyp; j <= hyp +i;j++){
						double ytry2;
						if(times2 == 0)
							ytry2 = sqrt((hyp*hyp)-((i-j)*(i-j)))+ytry;
						else
							ytry2 = -sqrt((hyp*hyp)-((i-j)*(i-j)))+ytry
					}
					if(isInt(ytry2) && x1 != i && y1 != ytry){

					}
				}
			} 
		}
	}
}