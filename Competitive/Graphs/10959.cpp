#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
	int t;
	scanf(" %d",&t);
	short fi = 0;
	while(t--){
		if(fi)
			puts("");
		int n,d;
		scanf(" %d %d",&n,&d);
		vector<vector<int>> graph(n);
		vector<int> nums(n,-1);
		for(int i = 0; i < d;++i){
			int a,b;
			scanf(" %d %d",&a,&b);
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		queue<int> q;
		nums[0] = 0;
		q.push(0);
		while(q.size()){
			int f = q.front();q.pop();
			for(int i = 0; i < graph[f].size();++i){
				if(nums[graph[f][i]] == -1){
					nums[graph[f][i]] = nums[f] + 1;
					q.push(graph[f][i]);
				}
			}
		}
		for(int i = 1; i < n;++i) printf("%d\n", nums[i]);
		fi = 1;
	}
	return 0;
}