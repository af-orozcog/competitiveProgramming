/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#define max(x,y)(x > y ? x:y);

using namespace std;

int main(){
	int siz;
	cin >> siz;
	int matrix[siz][siz];
	for(int i = 0; i < siz;++i){
		for(int j = 0; j < siz;++j){
			cin >> matrix[i][j];
			int sum = matrix[i][j];
			if(i != 0)
				sum += matrix[i-1][j];
			if(j != 0)
				sum += matrix[i][j-1];
			if(i != 0 && j != 0)
				sum -= matrix[i-1][j-1];
			matrix[i][j] = sum;
		}
	}
	int ans = -127*100*100;
	for(int i = 0; i < siz;++i){
		for(int j = 0; j < siz;++j){
			for(int m = i;m < siz;++m){
				for(int n = j; n < siz;++n){
					int sum = matrix[m][n];
					if(i != 0)
						sum -= matrix[i-1][n];
					if(j != 0)
						sum -= matrix[m][j-1];
					if(i != 0 && j != 0)
						sum += matrix[i-1][j-1];
					ans = max(ans,sum);
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}