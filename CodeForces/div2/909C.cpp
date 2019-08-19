/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<cstring>
#define ll long long

using namespace std;

ll memo[5000][5000];
ll M = 1000000007;
int N;
char stats[5000];

ll solve(int toTake,int identa){
	if(toTake == N)
		return 1;
	if(toTake > N)
		return 0;
	if(memo[toTake][identa] != -1)
		return memo[toTake][identa];
	ll add = 0;
	if(stats[toTake] == 'f'){
		return memo[toTake][identa] = solve(toTake+2,identa + 1)+1 % M;
	}
	ll ans = 0;
	for(int i = 0; i <= identa;++i){
		cout << toTake<< " " << identa << endl;
		ans += solve(toTake+1,i)%M;
	}
	return memo[toTake][identa] = ans;
}

int main(){
	scanf(" %d",&N);
	memset(memo,-1,sizeof(memo));
	for(int i = 0; i < N;++i){
		scanf(" %c",&stats[i]);
	}
	cout << solve(0,0) << endl;
	return 0;
}