/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<cstring>
using namespace std;

int x;
int y;
char matrix[100][100];
int movesA[] = {-1,1,-1,-1,1,1,0,0};
int movesB[] = {0,0,1,-1,1,-1,1,-1};
void solve(int i, int j){
	if(i < 0 || i >= x || j < 0 || j >= y)
		return;
	//cout << i << " " << j <<" " << matrix[i][j]<<endl;
	if(matrix[i][j] == '*')
		return;
	matrix[i][j] = '*';
	for(int m = 0; m < 8;++m){
		//cout << "here inside " << 
		solve(i+movesA[m],j+movesB[m]);
	}
}

int main(){
	while(1){
		cin >> x >> y;
		if(x == 0)
			break;
		memset(matrix,'*',sizeof(matrix));
		for(int i = 0; i < x;++i){
			for(int j = 0; j < y;++j){
				scanf(" %c",&matrix[i][j]);
			}
		}
		int ans = 0;
		for(int i = 0; i < x;++i){
			for(int j = 0; j < y;++j){
				if(matrix[i][j] == '@'){
					++ans;
					//cout << "here " << endl;
					solve(i,j);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
