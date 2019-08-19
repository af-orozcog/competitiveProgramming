#include<iostream>
#include<map>

using namespace std;

int main(){
	int n,m;
	scanf(" %d %d",&n,&m);
	int dp[n];
	dp[0] = 1;
	map<int,bool> unique;
	int v;
	scanf(" %d",&v);
	unique[v] = true;
	for(int i = 1; i < n;++i){
		int m;
		scanf(" %d",&m);
		if(unique.count(m) == 0){
			dp[i] = dp[i-1] +1;
			unique[m] = true;
		}
		else
			dp[i] = dp[i-1];
	}
	while(m--){
		int a;
		scanf(" %d",&a);
		--a;
		if(a)
			printf("%d\n",dp[n-1]-dp[a-1]);
		else
			printf("%d\n",dp[n-1]);
	}
	return 0;
}