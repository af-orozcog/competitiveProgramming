/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#define ll unsigned long long

using namespace std;

int main(){
	int N,M;
	bool first = true;
	while(cin >> N >> M){
		if(!first)
			cout << endl;
		ll matrix[N][N];
		int siz = N;
		for(int i = siz-1; i >= 0;--i){
			for(int j = 0; j < siz;++j){
				cin >> matrix[i][j];
			}
		}
		for(int i = 0; i < siz;++i){
			for(int j = 0; j < siz;++j){
				ll sum = matrix[i][j];
				if(i != 0)
					sum += matrix[i-1][j];
				if(j != 0)
					sum += matrix[i][j-1];
				if(i != 0 && j != 0)
					sum -= matrix[i-1][j-1];
				matrix[i][j] = sum;
			}
		}
		ll total = 0;
		for(int i = siz - M; i >= 0;--i){
			for(int j = 0; j < siz;++j){
				int x = i + M -1;
				int y = j + M - 1;
				if(x > siz - 1 || y > siz - 1)
					continue;
				ll sum = matrix[x][y];
				if(i != 0)
					sum -= matrix[i-1][y];
				if(j != 0)
					sum -= matrix[x][j-1];
				if(i != 0 && j != 0)
					sum += matrix[i-1][j-1];
				cout << sum << endl; 
				total += sum;
			}
		}
		cout << total << endl;
		first = false;
	}
	return 0;
}