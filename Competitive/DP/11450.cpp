/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

int M,C, price[21][21];
int memo[201][20];
int shop(int money,int g){
	if(money < 0) return -1000000;
	if(g == C) return M - money;
	if(memo[money][g] != -1) return memo[money][g];
	int ans = -1;
	for(int i = 1; i <= price[g][0];++i){
		ans = max(ans,shop(money - price[g][i],g+1));
	}
	return memo[money][g] = ans;
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
		memset(memo,-1, sizeof(memo));
		int ans = shop(M,0);
		if(ans < 0)
			cout << "no solution\n";
		else
			cout << ans <<  "\n";
	}
	return 0;
}