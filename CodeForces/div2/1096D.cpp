/**
* Shark puppet: "Yeah"
*/
#include<iostream>
#include<cstring>
#define ll long long
#define min(x,y)(x < y? x:y)
#include<climits>

using namespace std;

int N;
ll dp[5][100000];
ll p[100000];
char le[100000];
char ha[] = {'h','a','r','d'};

ll solve(int s,int pos){
	if(pos == N && s != 4)
		return 0;
	if(pos == N && s == 4)
		return LLONG_MAX;
	if(s == 4)
		return LLONG_MAX;
	if(dp[s][pos] != -1)
		return dp[s][pos];
	if(le[pos] == ha[s]){
		//cout << "s es" << s << " pos es " << pos << endl;
		ll a = p[pos] + solve(s,pos+1);
		ll b = solve(s+1,pos+1);
		//cout << " a es " << a <<endl;
		//cout << " b es "<<b << endl;
		return min(a,b);
	}
	return dp[s][pos] = solve(s,pos+1);
}

int main(){
	memset(dp,-1,sizeof(dp));
	scanf(" %d",&N);
	scanf(" %s",le);
	for(int i = 0; i < N;++i){
		cin >> p[i];
	}
	cout << solve(0,0)<<endl;
}