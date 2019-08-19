/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<cstring>
#define ll long long

using namespace std;
ll M = 100000000;

ll memo[110][110][2];
int k1;
int k2;

ll solve(int foot,int horse,int last){
	if(foot == 0 && horse == 0)
		return 1;
	if(foot == 0 && horse > k2)
		return 0;
	if(horse == 0 && foot > k1)
		return 0;
	if(memo[foot][horse][last] != -1)
		return memo[foot][horse][last];
	ll ans = 0;
	if(last){
		for(int i = 1;i <= k1 && i <= foot;++i){
			ans += solve(foot-i,horse,0) % M;
		}
	}
	else{
		for(int i = 1;i <= k2 && i <= horse;++i){
			ans += solve(foot,horse-i,1) % M;
		}
	}
	return memo[foot][horse][last] = ans;
}

int main(){
	int foot,hor;
	memset(memo,-1,sizeof(memo)); 
	scanf(" %d %d %d %d",&foot,&hor,&k1,&k2);
	ll ans = solve(foot,hor,0);
	ans += solve(foot,hor,1) ;
	ans = ans % M;
	cout << ans << endl;
	return 0;
}