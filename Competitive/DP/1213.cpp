#include<iostream>
#define ll long long
#include<cstring>
#include<vector>
#include<bitset>
#include<algorithm>
#define ll long long

using namespace std;


vector<int> primes;
ll dp[15][187][1121];
void sett(){
	bitset<1500> sieve;
	sieve.set();
	for(int i = 2; i < 1120;++i){
		if(sieve[i]){
			int m = 2;
			while(i*m < 1200){
				sieve.set(i*m,0);
				++m;
			}
			primes.push_back(i);
		}
	}
}

int solve(int k,int p,int n){
	if(n == 0 && k == 0)
		return 1;
	if(k == 0)
		return 0;
	if(n <= 0)
		return 0;
	if(p == 187)
		return 0;
	if(dp[k][p][n] != -1)
		return dp[k][p][n];
	int ans = solve(k-1,p+1,n-primes[p]) + solve(k,p+1,n);
	return dp[k][p][n] = ans;
}

int main(){
	memset(dp,-1,sizeof(dp));
	sett();
	while(1){
		int n,k;
		scanf(" %d %d",&n,&k);
		if(n == 0 && k == 0)
			break;
		printf("%d\n",solve(k,0,n));
	}
	return 0;
}