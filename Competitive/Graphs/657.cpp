/**
* I'm an Idiot
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int diX[] = {0,0,1,-1};
int diY[] = {1,-1,0,0};

int map[50][50];

int X,Y;
void DFSW(int x,int y){
	if(x < 0 || x >= Y || y < 0 || y >= X)
		return;
	if(map[x][y] != 2)
		return;
	map[x][y] = 0;
	for(int i = 0; i < 4;++i){
		DFSW(x+diX[i],y+diY[i]);
	}
}

int DFSN(int x,int y,int one){
	if(x < 0 || x >= Y || y < 0 || y >= X)
		return 0;
	if(map[x][y] == 0)
		return 0;
	int ans = 0;
	if(map[x][y] == 2 && one == 0){
		cout << x <<" " << y
		ans += 1;
		map[x][y] = 0;
		for(int i = 0; i < 4;++i){
			ans += DFSN(x+diX[i],y+diY[i],1);
		}
		return ans;
	}
	if(map[x][y] != 2 && one == 1)
		one = 0;
	map[x][y] = 0;
	for(int i = 0; i < 4;++i){
		ans += DFSN(x+diX[i],y+diY[i],one);
	}
	return ans;
}

int main(){
	int N = 0;
	while(cin >> X >> Y){
		if(X == 0)
			break;
		if(N != 0)
			cout << endl;
		++N;
		memset(map,0,sizeof(map));
		for(int i = 0; i < Y;++i){
			for(int j = 0; j < X;++j){
				char r;
				cin >> r;
				if(r == '*')
					map[i][j] = 1;
				else if(r == 'X')
					map[i][j] = 2;
			}
		}
		vector<int> ans;
		for(int i = 0; i < Y;++i){
			for(int j = 0; j < X;++j){
				if(map[i][j] == 1){
					//cout << "aqui "<< i << " "<<j <<endl;
					ans.push_back(DFSN(i,j,0));
				}
			}
		}
		for(int i = 0; i < Y;++i){
			for(int j = 0; j < X;++j){
				if(map[i][j] == 2){
			//		cout << i << " " << j << endl;
					map[i][j] = 0;
					for(int m = 0; m < 4;++m){
						DFSW(i+diX[m],j+diY[m]);
					}
					ans.push_back(1);
					DFSW(i,j);
				}
			}
		}
		sort(ans.begin(),ans.end());
		printf("Throw %d\n",N);
		for(int i = 0; i < ans.size();++i){
			if(i == 0)
				cout << ans[i];
			else
				cout << " " << ans[i];
		}
		cout << endl;
	}
	return 0;
}