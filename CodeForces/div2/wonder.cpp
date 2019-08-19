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
	if(a == b){
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
	}
	//cout << posN << endl;
	ll minAr = 21474836490;
	ll ansA = 0;
	ll ansB = 0; 
	if(posN == 0){
		if((a+1)*b >= total && (a+1)*b < a*(b+1)){
			cout << (a+1)*b << endl;
			cout << (a+1) << " "<< b << endl;
		}
		else{
			cout << a*(b+1) << endl;
			cout << a << " "<< b+1 << endl;
		}
		return 0;
	}
	ll last = minAr;
	for(ll i = posN; i >= 0; i--){
		ll posB = ((total-(a*b)-(b*i))/(a+i))+b;
		ll posA = a + i;
		ll posAr = posA * posB;
		if(posAr == total){
			cout << total << endl;
			cout << i + a << " " << posB << endl;
			return 0;
		}
		if(posAr < minAr){
			minAr = posAr;
			ansA = i + a;
			ansB = posB;
			last = minAr;
		}
		//cout << posAr << endl;
	}
	cout << minAr << endl;
	cout << ansA << " " << ansB << endl;
	return 0;
}