/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<cstring>
#define ll long long
#include<vector>

using namespace std;

ll M = 1000000007;

int main(){
	int N;
	scanf(" %d",&N);
	char stats[N];
	//memset(memo,-1,sizeof(memo));
	for(int i = 0; i < N;++i){
		scanf(" %c",&stats[i]);
	}
	ll dp[N];
	memset(dp,0,sizeof(dp));
	dp[0] = 1;
	int indent = 0;
	for(int i = 0;i < N;++i){
		if(stats[i] == 'f') ++indent;
		else{
			for(int j = 1; j <= indent;++j){
				dp[j] = (dp[j-1]+dp[j]) %M;
			}
		}
	}
	cout << dp[indent] << endl;
	return 0;
}