#include<iostream>
#include<cmath>
#define ll long long

using namespace std;

int main(){
	ll n,a,b;
	cin >> n >> a >> b;
	ll total = 6*n;
	if(a *b >= total){
		cout << a * b << endl;
		cout << a <<" "<< b<< endl;
		return 0;
	}
	ll posN = (((double)total - (double)(a*b))/(double)b);
	cout << posN << endl;
	if((a + posN) * b >= total){
			cout << (a + posN) * b << endl;
			cout << (posN + a) << " " << b << endl;
			return 0; 
		}
		else{
			for(ll i = 0; i < total; i++){
				ll posA = a + (total-(a*b)-(a*i))/(b+i);
				ll posB = b + i;
				if(posA * posB >= total){
					cout << posA * posB << endl;
					cout << posA << " " << posB << endl;
					return 0;
				}
			}
		}
	//cout << minAr << endl;
	//cout << ansA << " " << ansB << endl;
	return 0;
}