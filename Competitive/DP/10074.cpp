/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#define ll long long

using namespace std;

int main(){
	while(true){
		int M,N;
		cin >> M >> N;
		if(M == 0)
			break;
		ll matrix[M][N];
		for(int i = 0; i < M;++i){
			for(int j = 0; j < N;++j){
				ll sum;
				cin >> sum;
				if(sum == 1)
					sum = -100*100;
				else if(sum == 0 )
					sum = 1;
				if(i != 0)
					sum += matrix[i-1][j];
				if(j != 0)
					sum += matrix[i][j-1];
				if(i != 0 && j != 0)
					sum -= matrix[i-1][j-1];
				matrix[i][j] = sum;
			}
		}
		ll max = 0;
		for(int i = 0; i < M;++i){
			for(int j = 0; j < N;++j){
				for(int m = i; m < M;++m){
					for(int n = j; n < N;++n){
						ll sum = matrix[m][n];
						if(i != 0)
							sum -= matrix[i-1][n];
						if(j != 0)
							sum -= matrix[m][j-1];
						if(i != 0 && j != 0)
							sum += matrix[i-1][j-1];
						if(sum > max){
							max = sum;
						}
					}
				}
			}
		}
		cout << max << endl;
	}
	return 0;
}