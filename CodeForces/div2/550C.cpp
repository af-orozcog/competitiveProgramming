#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

string num;
short dp[3][8][100];

int ten(int n){
	int ans = 1;
	for(int i = 0; i < n;++i)
		ans *= 10;
	return ans;
}

bool solve(int i,int r ,int j){
	if(j < 0 && r == 0)
		return 1;
	if(j < 0)
		return 0;
	if(i == 3 && r == 0)
		return 1;
	if(i == 3)
		return 0;
	if(dp[i][r][j] != -1)
		return dp[i][r][j];
	int ans = 0;
	ans = (solve(i+1,(r+((num[j]-'0')*ten(i)))%8,j-1) ? 1:0);
	if(!ans)
	    ans = (solve(i,r,j-1) ? 2:0);
	return dp[i][r][j] = ans;
}


int main(){
	memset(dp,-1,sizeof(dp));
	cin >> num;
	vector<int> ans;
	solve(0,0,num.size()-1);
	int j = num.size()-1;
	int i = 0;
	int r = 0;
	//cout << dp[0][0][j] << endl;
	while(j >= 0 && i < 3){
		//cout << i << endl;
		if(dp[i][r][j] == 1){
			ans.push_back(j);
			r += ((num[j]-'0')*ten(i))%8;
			r = r % 8;
			i += 1;
			j -= 1;
		}
		else if(dp[i][r][j] == 2)
			j -= 1;
		else
			break;
	}
//	for(auto &b:ans) cout << b << " lil ";cout<< endl;
	reverse(ans.begin(),ans.end());
	if(ans.size() == 0){
		puts("NO");
		return 0;
	}
	puts("YES");
	if(num[ans[0]] == '0'){
		puts("0");
		return 0;
	}
	for(auto &b:ans)
		cout << num[b];
	cout << endl;
	return 0;
}