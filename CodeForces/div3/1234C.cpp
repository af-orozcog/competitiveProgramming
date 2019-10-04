#include<iostream>
#include<set>
#include<vector>
#include<cstring>

using namespace std;

char vals[2][200001];
int N;

bool solve(int r, int p, char l){
	if(p == N+1)
		return (r == 1);
	if(l == '1' && (vals[r][p]-'0' > 2)){
		if(r == 0)
			return solve(r,p+1,'3');
		else
			return solve(r,p+1,'6');
	}
	
	if(l == '2'){
		if(vals[r][p] == '2' || vals[r][p] == '1')
			return solve(r,p+1,l);
		else if(r == 0)
			return solve(r+1,p,'4');
		else
			return solve(r-1,p,'5');
	}
	if(l == '3'){
		if(vals[r][p] == '2' || vals[r][p] == '1')
			return solve(r,p+1,'2');
		else if(r == 0)
			return solve(r+1,p,'4');
	}
	
	if(l == '4' && (vals[r][p]-'0' > 2)){
		return solve(r,p+1,'6');
	}
	
	if(l == '5' && (vals[r][p]-'0' > 2)){
		return solve(r,p+1,'3');
	}
	
	if(l == '6'){
		if(vals[r][p] == '2' || vals[r][p] == '1')
			return solve(r,p+1,'2');
		else
			return solve(0,p,'5');
	}
	return false;
}

int main(){
	int t;
	scanf(" %d",&t);
	while(t--){
		memset(vals,0,sizeof(vals));
		scanf(" %d",&N);
		for(int i = 1; i <= N;++i)
			scanf(" %c",&vals[0][i]);
		for(int i = 1; i <= N;++i)
			scanf(" %c",&vals[1][i]);
		if(solve(0,1,'2'))
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
