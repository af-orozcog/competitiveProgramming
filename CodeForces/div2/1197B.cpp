#include<iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int num[n];
	int max = 0;
	int poM;
	for(int i = 0;i < n;++i){
		cin >> num[i];
		if(num[i] > max){
			max = num[i];
			poM = i;
		}
	}
	int r = poM +1;
	int l = poM - 1;
	int top = max;
	bool posi = true;
	while(r < n || l >= 0){
		if(r >= n){
			if(num[l] < top){
				top = num[l];
				--l;
			}
			else{
				posi = false;
				break;
			}
		}
		else if(l < 0){
			if(num[r] < top){
				top = num[r];
				++r;
			}
			else{
				posi = false;
				break;
			}
		}
		else if(num[r] > num[l]){
			if(num[r] < top){
				top = num[r];
				++r;
			}
			else{
				posi = false;
				break;
			}
		}
		else{
			if(num[l] < top){
				top = num[l];
				--l;
			}
			else{
				posi = false;
				break;
			}
		}
	}
	cout << (posi? "YES":"NO") << "\n";
	return 0;
}