#include<iostream>
#include<cstring>

using namespace std;

int movX[] = {0,0,1,-1};
int movY[] = {1,-1,0,0};

int m,n;
char map[20][20];

bool move(int x,int y,bool f){
	if(x < 0 || x >= m || y < 0 || y >= n)
		return false;
	if(map[x][y] == 0)
		return false;
	map[x][y] = 0;
	if((x == 0 || x == m - 1 || y == 0 || y == n-1) && f)
		return true;
	bool ans = false;
	for(int i = 0; i < 4;++i){
		ans = ans | move(x+movX[i],y+movY[i],true);
	}
	return ans;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> m >> n;
		memset(map,0,sizeof(map));
		int exi = 0;
		int lx,ly;
		for(int i = 0; i < m;++i){
			for(int j = 0; j < n;++j){
				char r;
				scanf(" %c",&r);
				if(r == '.'){
					map[i][j] = 1;
					if(i == 0 || i == m - 1 || j == 0 || j == n-1 ){
						++exi;
						lx = i;
						ly = j;
					}
				}
			}
		}
		if(exi <= 1 || exi > 2){
			cout << "invalid\n";
			continue;
		}
		if(move(lx,ly,false))
			cout << "valid\n";
		else
			cout << "invalid\n";
	}
	return 0;
}