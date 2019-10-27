#include<iostream>
#include<vector>
#include<cmath>
#define min(x,y)(x < y?x:y)

using namespace std;

int ans = 100000;
int tar;

void solve(int num, vector<int> &usen){
	if(num == 0){
		ans = min(ans,abs(num-tar));
		return;
	}
	if(num > 999)
		return;
	ans = min(ans,abs(num-tar));
	for(int i = 0,j = 0; i < 10;++i){
		if((j >= (int)usen.size()) ||(j < (int)usen.size() && i != usen[j]))
			solve((num*10)+i,usen);
		else if(j < (int)usen.size() && i == usen[j])
			++j;
	}
	return;
}

int main(){
	int n;scanf("%d",&n);
	vector<int> usen(n);
	for(int i = 0; i < n;++i)
		scanf(" %d",&usen[i]);
	scanf(" %d",&tar);
	for(int i = 0,j = 0; i < 10;++i){
		if((j >= (int)usen.size()) ||(j < (int)usen.size() && i != usen[j]))
			solve(i,usen);
		else if(j < usen.size() && i == usen[j])
			++j;
	}
	printf("%d\n",ans);
	return 0;
}