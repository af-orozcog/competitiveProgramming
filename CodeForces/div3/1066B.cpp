#include<iostream>
#include<vector>
#include<algorithm>
#define max(x,y)(x > y ? x:y)
#define min(x,y)(x < y ? x:y)

using namespace std;

int main(){
	int n,r;
	scanf(" %d %d",&n,&r);
	bool posi = 1;
	vector<pair<int,int>> seg;
	for(int i = 0; i < n;++i){
		int va;scanf(" %d",&va);
		if(va)
			seg.push_back({max(0,i-r+1),min(n-1,i+r-1)});
	}
	int needed = 0;
	int lastR = -1;
	for(int i = 0; i < seg.size();++i){
		int before = i;
		while(i < seg.size() && seg[i].first <= lastR+1){
			++i;
		}
		if(before == i)
			break;
		if(lastR == n-1)
			break;
		--i;
		++needed;
		lastR = seg[i].second;
	}
	if(lastR != n-1)
		puts("-1");
	else
		printf("%d\n",needed);
	return 0;
}