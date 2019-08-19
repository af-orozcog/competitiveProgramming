    /**
    * worried about TLE
    */
    #include<iostream>
    #include<vector>
    #include<cstring>
    #include<queue>
    #include<algorithm>
     
    using namespace std;
     
     
    bool marked[5000];
    int N;
    void bfs(int start,vector<vector<int>> &graph){
    	queue<int> q;
    	q.push(start);
    	marked[start] = true;
    	while(q.size()){
    		int f = q.front();q.pop();
    		for(int i = 0; i < (int)graph[f].size();++i){
    			if(!marked[graph[f][i]]){
    				q.push(graph[f][i]);
    				marked[graph[f][i]] = true;
    			}
    		}
    	}
    	//marked[start] = false;
    }
     
    int bfsTemp(int start,vector<vector<int>> &graph){
    	if(marked[start])
    		return 0;
    	bool mark[graph.size()];
    	memset(mark,false,sizeof(mark));
    	queue<int> q;
    	q.push(start);
    	int ans = 1;
    	mark[start] = true;
    	while(q.size()){
    		int f = q.front();q.pop();
    		//mark[f] = true;
    		for(int i = 0; i < (int)graph[f].size();++i){
    			if(!(marked[graph[f][i]] || mark[graph[f][i]])){
    				q.push(graph[f][i]);
    				mark[graph[f][i]] = true;
    				++ans;
    			}
    		}
    	}
    	return ans;
    }
     
    int main(){
    	int m,s;
    	cin >> N >> m >> s;
    	--s;
    	memset(marked,false,sizeof(marked));
    	vector<vector<int>> graph(N);
    	for(int i = 0; i < m;++i){
    		int from,to;
    		cin >> from >>to;
    		--from;--to;
    		graph[from].push_back(to);
    	}
    	bfs(s,graph);
    	vector<pair<int,int>> as;
    	for(int i = 0; i < N;++i){
    		int val = bfsTemp(i,graph);
    		as.push_back(make_pair(val,i));
    	}
    	sort(as.begin(),as.end());
    	reverse(as.begin(),as.end());
    	int ans = 0;
    	for(int i = 0; i < as.size();++i){
    		if(!marked[as[i].second]){
    			bfs(as[i].second,graph);
    			++ans;
    		}
    	}
    	cout << ans << endl;
    	return 0;
}
