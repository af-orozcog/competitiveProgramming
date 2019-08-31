#include<stdio.h>
#include<string>

int main(){
	int n,m;
	scanf(" %d %d",&n,&m);
	int matrix[n][m];
	for(int i = 0; i < n;++i)
		for(int j = 0; j < m;++j)
			scanf(" %d",&matrix[i][j]);
	int posi = 1;
	for(int i = 0; i < n && posi;++i){
		for(int j = 0; j < m && posi;++j){
			if(matrix[i][j] == 1){
				if(i == n-1){
					if(matrix[i-1][j] == 2){
						matrix[i-1][j] = 2;
						matrix[i-1][j]
					}
				}
			}
		}
	}
}