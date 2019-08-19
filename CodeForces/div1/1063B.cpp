#include<iostream>
#include<string>

using namespace std;

int x,y;
char map[2000][2000];
int move(int px, int py, bool m, int l, int r){ 
	if(px < 0 || px >= x || py < 0 || py >= y){
		return 0;
	}
	//cout << map[px][py] << endl;
	if(map[px][py] == '-')
		return 0;
	if(map[px][py] == '*')
		return 0;
	int ans = 1;
	map[px][py] = '-';
	if(l > 0)
		ans += move(px,py-1,0,l-1,r);
	if(r > 0)
		ans += move(px,py + 1, 0,l,r-1);
	ans += move(px -1,py,1,l,r);
	ans += move(px + 1,py,1,l,r);
	return ans;
}


int main(){
	//mem
	cin >> x >> y;
	int sx,sy;
	cin >> sx >> sy;
	int l,r;
	cin >> l >> r;
	for(int i = 0; i < x;++i){
		string read;
		cin >> read;
		for(int j = 0; j < y;++j){
			map[i][j] = read[j];
		}
	}
	cout << move(sx-1,sy-1,0,l,r) << endl;
	return 0;
}