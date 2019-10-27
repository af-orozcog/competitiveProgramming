#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

vector<int> pos;

void init(){
	int upto = (1<<6);
	for(int i = 1; i <= upto;++i){
		int tot = 0;
		int j = 1;
		int co = i;
		while(co){
			if(co&1)
				tot += j;
			j*=10;
			co = co >> 1;
		}
		//cout << tot << endl;
		pos.push_back(tot);
	}
}
int main(){
	init();
	int n;
	cin>>n;
	vector<int> dp(n+1,10000000);
	vector<vector<int>> ans(n+1);
	//cout << "lil" << endl;
	for(int i = 0; i < pos.size();++i){
		if(pos[i] >n)break;
		dp[pos[i]] = 1;
		ans[pos[i]].push_back(i); 
	}
	dp[0] = 0;
	for(int i = 1;i <= n;++i){
		int add = -1;
		int le = 0;
		if(dp[i] == 1) continue;
		for(int j = 0; j < pos.size();++j){
			if(i-pos[j] < 0)
				break;
			if(1 + dp[i-pos[j]] < dp[i]){
				dp[i] = 1+ dp[i-pos[j]];
				add = j;
				le = i - pos[j];
			}
		}
		for(int j = 0; j < ans[le].size();++j)
			ans[i].push_back(ans[le][j]);
		ans[i].push_back(add);
	}
	printf("%d\n",dp[n]);
	for(int i = 0; i < ans[n].size();++i)
		printf("%d ",pos[ans[n][i]]);
	puts("");
	return 0;
}