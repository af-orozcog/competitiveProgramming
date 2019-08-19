#include<iostream>
#include<map>
#include<vector>
#define ll long long

using namespace std;

int main(){
	int n;
	scanf(" %d",&n);
	vector<int> ans;
	int t;
	scanf(" %d",&t);
	for(int i = 0; i < n;++i){
		int x,y;
		cin >> x >> y;
		toAdd.push_back(make_pair(i+1,make_pair(x,y)));
	}
	map<pair<int,int>,bool> adde;
	if(solve(adde,ans)){
		puts("YES");
		for(int i = 0; i < ans.size();++i){
			printf("%d\n",ans[i]);
		}
	}
	else
		puts("NO");
	return 0;
}