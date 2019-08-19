/**
* I'm doing everything to be in the team again
*/
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

short dp[100][900];
int M,S;

char ansMax[100][500];
char ansMin[100][500];

bool solveMax(int t,int sum){
	if(sum < 0)
		return false;
	if(t == M && sum == 0)
		return true;
	else if(t == M)
		return false;
	if(dp[t][sum] != -1)
		return dp[t][sum];
	bool can = false;
	for(int i = 9; i >= 0;--i){
		if(solveMax(t+1,sum-i)){
			can = true;
			ansMax[t][sum] = i;
			break;
		}
	}
	return dp[t][sum] = can;
}
bool solveMin(int t, int sum){
	if(sum < 0)
		return false;
	if(t == M && sum == 0)
		return true;
	else if(t == M)
		return false;
	if(dp[t][sum] != -1){
		//cout << "sum" <<sum <<endl;
	//	cout << dp[t][sum] << endl;
		return dp[t][sum];
	}
	bool can = false;
	for(int i = 0; i < 10;++i){
		//cout << "entro? "<< sum << endl;
		if(solveMin(t+1,sum-i)){
		//	cout << "por que?" << endl;
			can = true;
			ansMin[t][sum] = i;
			break;
		}
	}
	return dp[t][sum] = can;
}

int main(){
	cin >> M >> S;
	memset(dp,-1,sizeof(dp));
	if(S == 0 && M == 1){
		cout << 0 <<" "<< 0 << endl;
		return 0;
	}
	else if(S == 0){
		cout << -1 << " " <<-1<< endl;
		return 0;
	}
	bool posi = false;
	for(int i = 9; i > 0;--i){
		if(solveMax(1,S-i)){
			ansMax[0][S] = i;
			posi = true;
			break;
		}
	}
	if(!posi){
		cout << -1 << " " << -1 << endl;
		return 0;
	}
	posi = false;
	memset(dp,-1,sizeof(dp));
	for(int i = 1; i < 10;++i){
		//cout << "S -i es"<< S-i <<endl;
		if(solveMin(1,S-i)){
			ansMin[0][S] = i;
			posi = true;
			break;
		}
	}
	if(!posi){
		cout << -1 << " " << -1 << endl;
		return 0;
	}
	string min = "";

	int SS = S;
	for(int i = 0; i < M;++i){
		int add = ansMin[i][SS];
		SS -= add;
		min += to_string(add);
	}
	SS = S;
	string max = "";
	for(int i = 0; i < M;++i){
		int add = ansMax[i][SS];
		SS -= add;
		max += to_string(add);
	}
	cout << min << " " << max << endl;
	return 0;
}