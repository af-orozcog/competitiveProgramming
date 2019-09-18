/**
* Why the fuck I am doing this Shit
*/
#include<iostream>
#include<cstring>
#include<map>

using namespace std;

int main(){
	int t;
	scanf(" %d",&t);
	short fi = 0;
	while(t--){
		if(fi)
			puts("");
		int r,c,n;
		scanf(" %d %d %d",&r,&c,&n);
		char map[r][c];
		for(int i = 0; i< r;++i){
			for(int j = 0; j < c;++j)
				scanf(" %c",&map[i][j]);
		}
		std::map< char,char> tr;
		tr['R'] = 'S';
		tr['S'] = 'P';
		tr['P'] = 'R'; 
		char temp[r][c];
		memset(temp,-1,sizeof(temp));
		for(int k = 0; k < n;++k){
			for(int i = 0; i < r;++i){
				for(int j = 0; j < c;++j){
					if(i > 0 && map[i-1][j] == tr[map[i][j]])
						temp[i-1][j] = map[i][j];
					if(j > 0 && map[i][j-1] == tr[map[i][j]])
						temp[i][j-1] = map[i][j];
					if(i < r-1 && map[i+1][j] == tr[map[i][j]])
						temp[i+1][j] = map[i][j];
					if(j < c-1 && map[i][j+1] == tr[map[i][j]])
						temp[i][j+1] = map[i][j];
					if(temp[i][j] == -1)
						temp[i][j] = map[i][j];
				}
			}
			memcpy(map,temp,sizeof(temp));
			memset(temp,-1,sizeof(temp));
		}
		for(int i = 0; i < r;++i){
			for(int j = 0; j < c;++j)
				printf("%c",map[i][j]);
			puts("");
		}
		fi = 1;
	}
	return 0;
}