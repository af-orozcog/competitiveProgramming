/**
* I'm an idiot
*/
#include<iostream>
#define ll long long

using namespace std;

int main(){
	int cas;
	cin >> cas;
	while(cas--){
		ll a,b;
		cin >> a >> b;
		//cout << a << endl;
		ll step = 0;
		while(a){
			if(a % b == 0){ 
				a /= b;
				++step;
			}
			else{
				ll vel = (a/b) * b;
				if(vel == 0){
					step += a;
					a = 0;
					continue;
				}
				ll vil = a - vel;
				step += vil;
				a = vel;
			}
		}
		cout << step << endl;
	}
	return 0;
}