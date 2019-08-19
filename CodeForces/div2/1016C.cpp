#include<iostream>
#include<cstring>
#define max(x,y)(x > y? x:y)

using namespace std;

int dp[2][300000];
int vals[2][300000];
int N;

int solve(int i,int p, int time){
	if(p == N)
		return 0;
	if(dp[i][p] != -1){
		cout << "entra?" << endl;
		return dp[i][p];
	}
	int ans = vals[i][p]*time;
	int ans1 = ans;
	int ans2 = ans;
	if(i == 0){
		if(p & 1)
			ans1 += solve(i,p+1,time+1);
		else{
			ans1 += solve(i+1,p,time+1);
			++time;
			for(int m = p +1; m <N;++m){
				ans2 += vals[i][m]*time;
				++time;
			}
			for(int m = N -1;m >= p;--m){
				ans2 += vals[i+1][m]*time;
				++time;
			}
		}
	}
	else{
		if(p & 1){
			ans1 += solve(0,p,time+1);
			++time;
			for(int m = p +1; m <N;++m){
				ans2 += vals[i][m]*time;
				++time;
			}
			for(int m = N -1;m >= p;--m){
				ans2 += vals[0][m]*time;
				++time;
			}
		}
		else
			ans1 += solve(i,p+1,time+1);
	}
	return dp[i][p] = max(ans1,ans2);
}

int main(){
	memset(dp,-1,sizeof(dp));
	cin >> N;
	for(int i = 0; i < N;++i){
		cin >> vals[0][i];
	}
	for(int i = 0; i < N;++i){
		cin >> vals[1][i];
	}
	cout << solve(0,0,0) << endl;
}
