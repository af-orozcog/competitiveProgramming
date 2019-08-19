#include<iostream>
#include<string>
#include<cstring>
#define max(x,y)(x > y? x:y)

using namespace std;

string one,two;

int dp[5][101];

int solve(int l, int p){
	if(p >= one.size())
		return 0;
	if(dp[l][p] != -1)
		return dp[l][p];
	int ans = 0;
	ans = max(ans,solve(0,p+1));
	if(one[p] == 'X' || two[p] == 'X')
		return dp[l][p] = solve(0,p+1);
	if(l == 0){
		if(p-1 >= 0 && one[p-1] != 'X')
			ans = max(ans,solve(1,p+1)+1);
		if(p-1 >= 0 && two[p-1] != 'X')
			ans = max(ans,solve(3,p+1)+1);
		if(p+1 < one.size() && one[p+1] != 'X')
			ans = max(ans,solve(2,p+2)+1);
		if(p+1 < one.size() && two[p+1] != 'X')
			ans = max(ans,solve(4,p+2)+1);
	}
	else if(l == 4 &&(p-1 >= 0 && one[p-1] != 'X'))
		ans = max(ans,solve(1,p+1)+1);
	else if(l==4){
		if(p+1 < one.size() && one[p+1] != 'X')
			ans = max(ans,solve(2,p+2)+1);
		if(p+1 < one.size() && two[p+1] != 'X')
			ans = max(ans,solve(4,p+2)+1);
	}
	else if(l== 2 && (p-1 >= 0 && two[p-1] != 'X'))
		ans = max(ans,solve(3,p+1)+1);
	else if(l == 2){
		if(p+1 < one.size() && one[p+1] != 'X')
			ans = max(ans,solve(2,p+2)+1);
		if(p+1 < one.size() && two[p+1] != 'X')
			ans = max(ans,solve(4,p+2)+1);
	}
	else if((l == 3 || l == 1)){
		if(p+1 < one.size() && one[p+1] != 'X')
			ans = max(ans,solve(2,p+2)+1);
		if(p+1 < one.size() && two[p+1] != 'X')
			ans = max(ans,solve(4,p+2)+1);
	}
	return dp[l][p] = ans;
}

int main(){
	cin >> one;
	cin >> two;
	memset(dp,-1,sizeof(dp));
	cout << solve(0,0) << endl;
	return 0;
}