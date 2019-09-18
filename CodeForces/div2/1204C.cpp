/**
* Not sure if this gonna work XD
*/
#include<iostream>
#include<cstring>
#include<vector>
#define min(x,y)(x < y?x:y)

using namespace std;

//int see[1000000];
//int dp[1000000][1000000];
int dp[105][105];
int matrix[105][105];
//int N;

int main(){
	int n,s;
	//memset(dp,-1,sizeof(dp));
	scanf(" %d",&n);
	for(int i = 0; i < n;++i){
		for(int j = 0; j < n;++j){
			dp[i][j] = 100000000;
			if(i == j)
			    dp[i][j] = 0;
		}
	}
	for(int i = 0; i < n;++i){
		for(int j = 0; j < n;++j){
			char va;
			scanf(" %c",&va);
			if(va == '1'){
				matrix[i][j] = 1;
				dp[i][j] = 1;
			}
		}
	}
	scanf(" %d",&s);
	int nums[s];
	for(int i = 0; i < s;++i){scanf(" %d",&nums[i]);--nums[i];}
	for(int k = 0; k < n;++k){
		for(int i = 0; i < n;++i){
			for(int j = 0; j < n;++j)
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]); 
		}
	}
	//cout << matrix[nums[0]][nums[s-1]] << endl;
	vector<int>st;
	st.push_back(nums[0]);
	st.push_back(nums[1]);
	for(int i =2; i<s; i++){
		int x = st[st.size()-2];
		int y = st[st.size()-1];
		if(dp[x][y]+dp[y][nums[i]]==dp[x][nums[i]])
			st.pop_back();
		st.push_back(nums[i]);
	}
	printf("%d\n",(int)st.size());
	for(int i = 0; i < st.size();++i){
		if(i == 0)
			printf("%d",st[i]+1);
		else
			printf(" %d",st[i]+1);
	}
	puts("");
	return 0;
}