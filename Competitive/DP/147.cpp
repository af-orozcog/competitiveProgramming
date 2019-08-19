#include<iostream>
#include<cstring>
#define ll long long

using namespace std;

ll dp[11][30005];
int coins[] = {5,10,20,50,100,200,500,1000,2000,5000,10000};
ll solve(int c,int a){
	if(a == 0)
		return 1;
	if(a < 0 || c == 11)
		return 0;
	if(dp[c][a] != -1){
		return dp[c][a];
	}
	ll ans = solve(c+1,a) + solve(c,a-coins[c]);
	return dp[c][a] = ans;
}

int main(){
	while(1){
		memset(dp,-1,sizeof(dp));
		double val;
		cin >> val;
		if(val == 0.0)
			break;
		//int so = (int)(val*100.0);
		//cout << so << endl;
		//cout << static_cast<int>(val * 100 + 0.5) << endl;
		printf("%6.2f%17llu\n", val, solve(0,static_cast<int>(val * 100 + 0.5)));
	}
	return 0;
}