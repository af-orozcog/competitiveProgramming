/**
* I'm sorry I was an Idiot
*/
#include<stdio.h>
#include<vector>
#include<algorithm>
#define max(x,y)(x > y?x:y)

using namespace std;

bool com(const pair<int,int> a, const pair<int,int> b){
	if(a.first < b.first)
		return true;
	if(a.first > b.first)
		return false;
	else
		return a.second < b.second;
}

int main(){
	while(true){
		int num;
		scanf(" %d",&num);
		if(num == 0)
			break;
		vector<pair<int,int>> blocks(num);
		for(int i = 0; i < num;++i){
			int l,r;
			scanf(" %d %d",&l,&r);
			blocks[i] = make_pair(l,r);
		}
		sort(blocks.begin(), blocks.end(),com);
		int memo[num];
		memo[0] = 1;
		int valmax = 1;
		for(int i = 1; i < num;++i){
			int ans = 1;
			for(int j = i -1;j >= 0;--j){
				if(blocks[j].first <= blocks[i].first
					&& blocks[j].second <= blocks[i].second)
					ans = max(memo[j]+ 1,ans);
			}
			memo[i] = ans;
			valmax = max(valmax,ans);
		}
		printf("%d\n",valmax);
	}
	puts("*");
	return 0;
}