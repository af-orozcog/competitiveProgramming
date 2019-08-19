#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

struct SO{
	int s = 0;
	int n = 0;	
};

vector<int> bfs(int s,vector<vector<int>> &graph, vector<bool> &res){
	//cout << "hi " << s<<endl;
	vector<int> parent(graph.size(),-1);
	vector<int> ans;
	parent[s] = s;
	queue<int> q;
	q.push(s);
	//cout << "lik" << endl;
	while(q.size()){
		int f = q.front();q.pop();
		for(int i = 0; i < (int)graph[f].size();++i){
			if(parent[graph[f][i]] == -1){
				parent[graph[f][i]] = f;
				q.push(graph[f][i]);
			}
		}
	}
	//cout << "lel" << endl;
	SO imp[graph.size()];
	for(int i = 0; i < graph.size();++i){
		int dad = parent[i];
		imp[dad].s++;
		if(res[i])
			imp[dad].n++; 
	}
	for(int i = 0; i < graph.size();++i){
		//cout << i << " " <<imp[i].n<<endl;
		if(i == s)
			continue;
		if(!res[i] && imp[i].n == 0){
			ans.push_back(i);
		}
	}
	sort(ans.begin(),ans.end());
	return ans;
}

int main(){
	int n;
	scanf(" %d",&n);
	vector<vector<int>> graph(n);
	vector<bool> resp(n);
	int dad;
	for(int i = 0; i < n;++i){
		int val, re;
		scanf(" %d %d",&val,&re);
		--val;
		if(val == -2){
			dad = i;
			continue;
		}
		graph[val].push_back(i);
		graph[i].push_back(val);
		resp[i] = re?false:true;
	}
	//cout <<"lilll\n";
	vector<int> ans = bfs(dad,graph,resp);
	if(ans.size() == 0){
		puts("-1");
		return 0;
	}
	for(int i = 0; i < ans.size();++i){
		if(i == 0)
			printf("%d",ans[i]+1);
		else
			printf(" %d",ans[i]+1);
	}
	puts("");
}