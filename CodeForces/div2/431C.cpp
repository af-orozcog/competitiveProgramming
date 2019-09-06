#include<iostream>
#define ll long long
#define M 1000000007
#include<cstring>

using namespace std;

int main(){
	int n,k,d;
	scanf(" %d %d %d",&n,&k,&d);
	ll dp[2][2][n+1];
	memset(dp,0,sizeof(dp));
	dp[0][0][0] = 1;
	ll ans = 0;
	for(int l = 0; l < n+1;++l){
		for(int i = 0; i < n;++i){
			if(dp[0][0][i] != 0){
				for(int j = 1;j<= k;++j){
					if(i + j <= n){
						if(j >= d)
							dp[1][1][i+j] = (dp[1][1][i+j] + dp[0][0][i])%M;
						else
							dp[1][0][i+j] = (dp[1][0][i+j] + dp[0][0][i])%M;
					}
				}
			}
			if(dp[0][1][i] != 0){
				//cout <<" donde entra " <<i;
				for(int j = 1;j<= k;++j){
					if(i + j <= n)
						dp[1][1][i+j] = (dp[1][1][i+j] + dp[0][1][i])%M;
				}
			}
		}
		/*cout << endl;
		for(int i = 0; i <= n;++i)
			cout << dp[1][0][i] << " ";
		cout << endl;
		for(int i = 0; i <= n;++i)
			cout << dp[1][1][i] << " ";
		cout << endl;*/
		ans += dp[1][1][n];
		ans = ans % M;
		//cout << "ans is " << ans<< endl;
	 	memcpy(dp[0],dp[1],sizeof(dp[1]));
		memset(dp[1],0,sizeof(dp[1]));
	}
	cout << ans << endl;
	return 0;
}