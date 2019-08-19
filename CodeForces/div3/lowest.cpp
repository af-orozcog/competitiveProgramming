#include <iostream>
using namespace std;
int gcd(int a, int b) {
   if (b == 0)
   return a;
   return gcd(b, a % b);
}
int main(){
	int elem;
	cin >> elem;
	int numbers[elem];
	for(int i = 0; i < elem; i++){
		int val;
		cin >> val;
		numbers[i] = val;
	}
	int minimum = 0;
	int flag = 0;
	int ires = 0;
	int jres = 0;
	for(int i = 0; i < elem; i++){
		for(int j = i+1; j < elem; j++){
			if(flag == 0){
				minimum = (numbers[i]*numbers[j])/(gcd(numbers[i],numbers[j]));
				ires = i;
				jres = j; 
				flag = 1;
			}
			else{
				int nu = (numbers[i]*numbers[j])/(gcd(numbers[i],numbers[j]));
				if(nu < minimum){
					minimum = nu;
					ires = i;
					jres = j;
				}
			}
		}
	}
	cout << ires+1 << " " << jres+1 << endl;
	return 0;
}