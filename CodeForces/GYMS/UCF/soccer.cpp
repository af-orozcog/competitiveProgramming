#include<bits/stdc++.h>

using namespace std;

int dp[12][(1<<12)];
pair<int,int> opponents[12];
pair<int,int> team[12];
int N;

bool possible(int i, int j){
	pair<int,int> coor1 = team[i];
	pair<int,int> coor2 = team[j];
	pair<int,int> m = {coor1.second-coor2.second,coor1.first-coor2.first};
	if(m.second < 0){
		m.first = -m.first;
		m.second = -m.second;
	}
	if(m.second == 0){
	    for(int i = 0; i < N;++i){
	        if(opponents[i].first == coor1.first && coor1.second >= min(coor1.second,coor2.second) &&
	            coor1.second <= max(coor1.second,coor2.second))
	            return false;
	    }
	    return true;
	}
	if(m.first == 0){
	    for(int i = 0; i < N;++i){
	        if(opponents[i].second == coor1.second && coor1.first >= min(coor1.first,coor2.first) &&
	            coor1.first <= max(coor1.first,coor2.first))
	            return false;
	    }
	    return true;
	}
	pair<int,int> b = {-m.first*coor1.first,m.second};
	b.first = b.first + (coor1.second*b.second);
	if(b.second < 0){
		b.first = -b.first;
		b.second = -b.second;
	}
	
	
	for(int i = 0; i < N;++i){
		if(opponents[i].first > max(coor1.first,coor2.first)
			|| opponents[i].first < min(coor1.first,coor2.first)
			|| opponents[i].second > max(coor1.second,coor2.second)
			|| opponents[i].second < min(coor1.second,coor2.second))
			continue;
		pair<int,int> temp = {opponents[i].first*m.first,m.second};
		temp.first = temp.first + b.first;
		if(temp.first % temp.second)
			continue;
		int comp = temp.first / temp.second;
		if(comp == opponents[i].second)
			return false;
	}
	return true;
}

int solve(int l, int mask){
	if(l == N-1)
		return 0;
	if(dp[l][mask] != -1)
		return dp[l][mask];
	int ans = 10000000;
	for(int i = 0; i < N;++i){
	  //  cout << ((1<<i)&mask) << endl;
		if(((1<<i)& mask) == 0){
			if(possible(i,l))
				ans = min(ans,solve(i,((1<<i)|mask))+1);
		}
	}
	return dp[l][mask] = ans;
}
 
int main(){
	scanf(" %d",&N);
	memset(dp,-1,sizeof(dp));
	for(int i = 0; i < N;++i)
		scanf(" %d %d",&team[i].first,&team[i].second);
	for(int i = 0; i < N;++i)
		scanf(" %d %d",&opponents[i].first,&opponents[i].second);
	int ans = solve(0,1);
	cout << (ans == 10000000 ? -1: ans) << endl;
	return 0;
}