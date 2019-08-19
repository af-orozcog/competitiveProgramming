/**
* I'm an idiot
*/
#include<iostream>

using namespace std;

int main(){
	int cas;
	cin >> cas;
	while(cas--){
		int big;
		cin >> big;
		int vals[big];
		for(int i = 0; i < big;i++){
			cin >> vals[i];
		}
		int i = 0, j = 1;
		int ans = vals[i] - vals[j];
		if(ans < 0){
			i = j;
			j = i + 1;
		}
		while(i < big - 1 && j < big){
			int ot = vals[i] - vals[j];
			if(ot > ans)
				ans = ot;
			if(ot < 0){
				i = j;
				j = i + 1;
				continue;
			}
			j++;
		}
		cout << ans << endl;
	}
	return 0;
}