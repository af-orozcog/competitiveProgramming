/**
* I do this because of Valentina, she motivates me :)
*/
#include<iostream>
#include<cstring>
#define max(x,y)(x > y ? x:y)
#define ll long long

using namespace std;

int main(){
	int n;
	scanf(" %d",&n);
	ll dp[100001];
	ll freq[100001];
	memset(dp,0,sizeof(dp));
	memset(freq,0,sizeof(freq));
	for(int i = 0; i < n;++i){
		int val; cin >> val;
		freq[val] += val;
	}
	dp[1] = freq[1];
	//cout << dp[1] << endl;
	dp[2] = freq[2];
	//cout << dp[2] << endl;
	for(int i = 2; i <= 100000;++i)
		dp[i] = max(dp[i-1],freq[i]+dp[i-2]);
	cout << dp[100000] << endl;
	return 0;
}