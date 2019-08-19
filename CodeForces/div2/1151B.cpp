/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<cstring>
#include<vector>
#define max(x,y)(x>y?x:y)

using namespace std;
short dp[500][1023];
int N,M;
short nums[500][500];
short id[500][1023];

short solve(int r,int v){
	if(r == N){
		if(v > 0)
			return 1;
		else
			return 0;
	}
	if(dp[r][v] != -1)
		return dp[r][v];
	int ans = 0;
	for(int i = 0; i < M;++i){
		int neV = v ^ nums[r][i];
		ans = max(ans,solve(r+1,neV));
		if(ans > 0){
			id[r][v] = i;
			return dp[r][v] =  1;
		}
	}
	return dp[r][v] = ans;
}

int main(){
	scanf(" %d %d",&N,&M);
	memset(dp,-1,sizeof(dp));
	for(int i = 0; i < N;++i){
		for(int j = 0; j < M;++j){
			cin >> nums[i][j];
		}
	}
	int ans = solve(0,0);
	if(ans){
		/*for(int i = 0; i < N;++i){

		}*/
		puts("TAK");
		int val = 0;
		for(int i = 0; i < N;++i){
			if(i == 0)
				cout << id[i][val]+1;
			else
				cout <<" " <<id[i][val]+1;
			val = val ^ nums[i][id[i][val]];
		}
		cout << endl;
	}
	else
		puts("NIE");
	return 0;
}