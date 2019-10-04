#include<iostream>
#define ll long long
#define M 1000000007

using namespace std;
short pos[1001][1001];

int main(){
	int h,w;
	scanf(" %d %d",&h,&w);
	for(int i = 0; i < h;++i){
		int va;
		scanf(" %d",&va);
		int j = 0;
		for(; j < va;++j)
			pos[i][j] = 1;
		if(j < w)
			pos[i][j] = 2;
	}
	/*for(int i = 0; i < h;++i){
		for(int j = 0; j < w;++j){
			cout << pos[i][j] << " ";
		}
		cout << endl;
	}*/
	bool can = 1;
	for(int i = 0; i < w;++i){
		int va;scanf(" %d",&va);
		int j = 0;
		for(; j < va;++j){
			if(pos[j][i] == 2){
				//cout << j << "  " << i << endl;
				can = 0;
			}
			pos[j][i] = 1;
		}
		if(j < h){
			if(pos[j][i] == 1)
				can = 0;
			pos[j][i] = 2;
		}
	}
	if(!can){
		puts("0");
		return 0;
	}
	ll ans = 1;
	for(int i = 0; i < h;++i){
		for(int j = 0; j < w;++j){
			if(pos[i][j] == 0){
				ans = ans << 1;
				ans = ans % M;
			}
		}
	}
	cout << ans << endl;
	return 0;
}