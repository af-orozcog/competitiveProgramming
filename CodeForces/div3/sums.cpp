#include<iostream>
#define ll long long

using namespace std;

int main(){
	ll nums[4];
	for(int i = 0; i < 4; i++){
		ll val;
		cin >> val;
		nums[i] = val;
	}
	int marked1;
	for(int i = 0; i < 4; i++){
		ll totalSum = 0;
		for(int j = 0; j < 4;j++){
			totalSum += nums[i]- nums[j];
		}
		if(totalSum == nums[i]){
	//		cout << "aqui?" << endl;
			marked1 = i;
			break;
		}
	}
	ll a;
	int marked3;
	//cout << "el marcado es: " << nums[marked3] << endl; 
	for(int i = 0; i < 4; i++){
		if(i != marked1){
			ll posi = nums[marked1] - nums[i];
			//cout << "posi es: " << posi << endl;
			ll total = 0;
			for(int j = 0; j < 4; j++){
				if(j != marked1 && j != i)
					total += nums[j] - posi;
			}
			if(total == nums[i]){
				//cout << "entro aqui?" << endl;
				marked3 = i;
				a = posi;
				break;
			}
		}
	}
	ll b;
	ll c;
	int m = 0;
	int i = 0;
	while(i < 4){
		if(i != marked1 && i!= marked3){
			if(m == 0){
				b = nums[i] - a;
				m++;
			}
			else
				c = nums[i] - a;
		}
		i++;
	}
	cout << a << " " << b << " " << c << endl;
}