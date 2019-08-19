    #include<iostream>
    #include<vector>
    #include<algorithm>
    #include<queue>
    #include<cmath>
     
    using namespace std;
     
     
    int UF[100000];
    int rk[100000];
     
    void sett(int n){
    	for(int i = 0;i < n;++i){
    		UF[i] = i;
    		rk[i] = 1;
    	}
    }
     
    int search(int i){
    	return i == UF[i] ? i: (UF[i] = search(UF[i]));
    }
     
    bool connected(int x, int y){
    	return search(x) == search(y);
    }
     
    void connect(int x, int y){
    	int dadX = search(x),dadY = search(y);
    	if(dadX != dadY){
    		if(rk[dadX] > rk[dadY]){
    			UF[dadY] = dadX;
    		}
    		else{
    			UF[dadX] = dadY;
    			if(rk[dadX] == rk[dadY]) ++rk[dadY];
    		}
    	}
    }
     
    int bfs(int s, vector<vector<pair<int,int>>> &graph, vector<int> &spe){
    	vector<pair<int,int>> pa(graph.size(),make_pair(-1,-1));
    	pa[s].first = s;
    	queue<int> q;
    	q.push(s);
    	//cout << "lul" << endl;
    	while(q.size()){
    		int f = q.front();q.pop();
    		for(int j = 0; j < (int)graph[f].size();++j){
    			if(pa[graph[f][j].first].first == -1){
    				pa[graph[f][j].first].first = f;
    				pa[graph[f][j].first].second = graph[f][j].second;
    				q.push(graph[f][j].first);
    			}
    		}
    	}
    	//cout << "lel" << endl;
    	int ans = 0;
    	for(int i = 1; i < spe.size();++i){
    		int ro = 0;
    		int m = spe[i];
    		while(pa[m].first != m){
    			ro = max(ro,pa[m].second);
    			m = pa[m].first;
    		}
    		ans = max(ans,ro);
    	}
    	return ans;
    }
     
    bool same(vector<int> &see, int *x){
        int w = *x;
        //cout << w << endl;
        //cout << search(0) << endl;
        //cout << search(w) << endl;
        if(connected(see[0],see[w])){
            while(w < see.size() && connected(see[0],see[w])){
                w = w + 1;
            }
            if(w == see.size()){
                //cout << "here  " << endl;
                return true; 
            }
            *x = w;
        }
        return false;
    }

    int main(){
    	int n,m,k;
    	scanf(" %d %d %d",&n,&m,&k);
    	sett(n);
    	vector<int> special(k);
    	for(int i = 0; i < k;++i){
    		cin >> special[i];
    		--special[i]; 
    	}
    	vector<pair<int,pair<int,int>>> edges(m);
    	for(int i = 0; i < m;++i){
    		int a,b,c;
    		cin >> a >> b >>c;
    		--a;--b;
    		edges[i] = make_pair(c,make_pair(a,b));
    	}
    	sort(edges.begin(),edges.end());
        int last = 0;
        int w = 1;
    	for(int i = 0; i < m && !same(special,&w);++i){
            int a = edges[i].second.first, b = edges[i].second.second;
            if(connected(a,b))
    	       continue;
    	   connect(a,b);
    	   last = edges[i].first;
        }
    	for(int i = 0; i < k;++i){
    		if(i == 0)
    			printf("%d",last);
    		else
    			printf(" %d",last);
    	}
    	puts("");
    	return 0;
    }