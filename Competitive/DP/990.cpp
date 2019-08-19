#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int dp[31][1002];
int taken[31][1002];
int net[31][1002];
int n;
int w;
vector<pair<int,int>> vals(30);

int solve(int p, int t){
	if(t < 0)
		return -1000000000;
	if(p == n)
		return 0;
	if(dp[p][t] != -1)
		return dp[p][t];
	int ans = 0;
	int ans1 = vals[p].second + solve(p+1,t-(vals[p].first*w*3));
	if(ans1 > ans){
		ans = ans1;
		net[p][t] = t-(vals[p].first*3*w);
		taken[p][t] = p;
	}
	int ans2 = solve(p+1,t);
	if(ans2 > ans){
		ans = ans2;
		net[p][t] = t;
		taken[p][t] = -1;
	}
	return dp[p][t] = ans;
}

int main(){
	int t;
	bool f = true;
	while(cin >> t >> w){
		if(!f)
			cout << endl;
		memset(dp,-1,sizeof(dp));
		memset(net,-1,sizeof(net));
		memset(taken,-1,sizeof(taken));
		scanf(" %d",&n);
		for(int i = 0; i < n;++i){
			int d,c;
			scanf(" %d %d",&d,&c);
			vals[i] = {d,c};
		}
		printf("%d\n", solve(0,t));
		vector<pair<int,int>> treas;
		int co = t;
		int i = 0;
		while(i < n && net[i][co] != -1){
			if(taken[i][co] != -1)
				treas.push_back(vals[i]);
			co = net[i][co];
			++i;
		}
		cout << treas.size() << endl;
		for(int i = 0; i < treas.size();++i){
			cout << treas[i].first << " " << treas[i].second << endl;
		}
		f = false;
	}
	return 0;
}