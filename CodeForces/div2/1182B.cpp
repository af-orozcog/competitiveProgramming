/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<string>

using namespace std;

int main(){
	int x,y;
	cin >> x >> y;
	string map[x];
	for(int i = 0; i < x;++i){
		cin >> map[i];
	}
	int posi = 0;
	for(int i = 1; i < x-1 && posi == 0;++i){
		for(int j = 1; j < y-1;++j){
			if(map[i][j] == '*'){
				if(map[i+1][j] == '*' && map[i-1][j] == '*'
					&& map[i][j+1] == '*' && map[i][j-1] == '*'){
					map[i][j] = '.';
					posi = 1;
					int up = i -1;
					int down = i + 1;
					int right = j + 1;
					int left =  j - 1;
					for(int m = up; m >= 0;--m){
						if(map[m][j] != '*')
							break;
						map[m][j] = '.';
					}
					for(int m = down; m < x;++m){
						if(map[m][j] != '*')
							break;
						map[m][j] = '.';
					}
					for(int m = right; m < y;++m){
						if(map[i][m] != '*')
							break;
						map[i][m] = '.';
					}
					for(int m = left; m >= 0;--m){
						if(map[i][m] != '*')
							break;
						map[i][m] = '.';
					}
					break;
				}
			}
		}
	}
	if(posi){
		//puts("entro aqui");
		for(int i = 0; i < x && posi == 1;++i){
			for(int j = 0; j < y;++j){
				if(map[i][j] == '*'){
					posi = 0;
					break;
				}
			}
		}
	}
	if(posi)
		puts("YES");
	else
		puts("NO");
	return 0;
}