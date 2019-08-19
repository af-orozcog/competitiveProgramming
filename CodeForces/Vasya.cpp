#include <iostream>
#include <cstdlib>
#include <tgmath.h> 
using namespace std;
int numTo(int x, int y , int d){
	double dif = (double)(y - x);
	dif = abs(dif);
	double dm = (double) d;
	return (int)ceil(dif / dm);
}

int calcula(int n, int x, int y, int d){
	if(y == 1) return numTo(1,x,d);
	if(y == n) return numTo(x,n,d);
	if(x == y) return 0;
	int resA = (y - 1) % d;
	int resB = (n - y) % d;
	bool a = false;
	bool b = false;
	if(resA == 0)
		a = !a;
	if(resB == 0)
		b = !b;
	int ne = abs(y - x);
	double res = ne / (double) d;
	int ress = (int)res;
	if(resA != 0 && resB != 0 && (res - (double)ress) != 0.0) return -1;
	if((res - (double)ress) == 0.0) return ress;
	resA = (y - 1) / d;
	resB = (n - y) / d;
	if(a && b){
		int minTo = resA + numTo(1, x, d) < resB + numTo(x,n,d) ? resA + numTo(1, x, d) : resB + numTo(x,n,d);
		return minTo;
	}
	if(a)
		return resA + numTo(1, x, d);
	return resB + numTo(x,n, d);
}

int main(){
	int cas;
	cin >> cas;
	for(int i = 0; i < cas; i++){
		int n,x,y,d;
		cin >> n >> x >> y >> d;
		cout << calcula(n,x,y,d) << '\n';
	}
	return 0;
}