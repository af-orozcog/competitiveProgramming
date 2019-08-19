    #include<iostream>
        #include<vector>
        #include<queue>
        #include<climits>
        #define ll long long
         
        using namespace std;
         
         
        int main(){
            int n,m,k;
            cin >> n >> m >> k;
            vector<vector<pair<int,ll>>> graph(n);
            for(int i = 0; i < m;++i){
                int a,b;
                ll l;
                cin >> a >> b >> l;
                --a;--b;
                graph[a].push_back(make_pair(b,l));
                graph[b].push_back(make_pair(a,l));
            }
            vector<pair<ll,bool>> dist(n,make_pair(LLONG_MAX));
            int us = 0;
            for(int i = 0; i < k;++i){
                int s;
                ll l;
                cin >> s >> l;
                --s;
                if(l < dist[s].first){
                    if(dist[s].first != LLONG_MAX)
                        ++us;
                    dist[s].first = l;
                    dist[s].second = true;
                }
                else if(l >= dist[s].first)
                    ++us;
            }
            dist[0].first = 0;
            dist[0].second = false;
            priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> q;
            q.push(make_pair(0,0));
            while(q.size()){
                pair<ll,int> f = q.top();
                int u = f.second;
                q.pop();
                if(f.first > dist[u].first) continue;
                for(int i = 0; i< (int)graph[u].size();++i){
                    int to = graph[u][i].first; ll di = graph[u][i].second;
                    if(dist[u].first + di < dist[to].first){
                        if(dist[to].second)
                            ++us;
                        dist[to].first = dist[u].first + di;
                        dist[to].second = false;
                        q.push(make_pair(dist[to].first,to));
                    }
                    else if(dist[u].first + di == dist[to].first && dist[to].second){
                        ++us;
                        dist[to].first = dist[u].first + di;
                        dist[to].second = false;
                        q.push(make_pair(dist[to].first,to));
                    }
                }
            }
            cout << us << endl;
            return 0;
        }