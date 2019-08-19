/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<cstring>
using namespace std;

int M,C;
bool pos[2][201];
int price[20][21];

void solve(){
	for(int i = 1; i <= price[0][0];++i){
		if(M - price[0][i] >= 0){
			pos[0][M-price[0][i]] = true;
			//cout << "entro aqui"<< endl;
		}
	}
	int m = 1;
	while(m < C){
		for(int j = 0; j < 201;++j){
			if(pos[0][j]){
				for(int i = 1; i <= price[m][0];++i){
					if(j - price[m][i] >= 0){
						pos[1][j-price[m][i]] = true;
					}
				}
			}
		}
		for(int i = 0; i < 201;++i){
			pos[0][i] = pos[1][i];
			pos[1][i] = false;
		}
		++m;
	}
}

int main(){
	int cas;
	cin >> cas;
	while(cas--){
		cin >> M >> C;
		for(int i = 0; i < C;++i){
			cin >> price[i][0];
			for(int j = 1; j <= price[i][0];++j){
				cin >> price[i][j];
			}
		}
		memset(pos,false,sizeof(pos));
		solve();
		int i = 0;
		while(i < 201 && !pos[0][i]){++i;}
		if(i != 201)
			printf("%d\n",M-i);
		else
			printf("no solution\n");
	}
}