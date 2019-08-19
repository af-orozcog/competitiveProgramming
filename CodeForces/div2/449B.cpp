#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#define ll long long
     
    using namespace std;
     
     
    int main(){
        int n,m,k;
        cin >> n >> m >> k;
        vector<vector<pair<bool,pair<int,ll>>>> graph(n);
        for(int i = 0; i < m;++i){
            int a,b;
            ll l;
            cin >> a >> b >> l;
            --a;--b;
            graph[a].push_back(make_pair(false,make_pair(b,l)));
            graph[b].push_back(make_pair(false,make_pair(a,l)));
        }
    for(int i = 0; i < k;++i){
        int s;
        ll l;
        cin >> s >> l;
        --s;
        graph[0].push_back(make_pair(true,make_pair(s,l)));
    }
    vector<pair<ll,bool>> dist(n,make_pair(LLONG_MAX,false));
    dist[0].first = 0;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> q;
    q.push(make_pair(0,0));
    int used = 0;
    while(q.size()){
        pair<ll,int> f = q.top();
        int u = f.second;
        q.pop();
        if(f.first > dist[u].first) continue;
        for(int i = 0; i< (int)graph[u].size();++i){
            int to = graph[u][i].second.first; ll di = graph[u][i].second.second;
            //cout << "di es " << di << endl; 
            if(dist[u].first + di < dist[to].first){
                dist[to].first = dist[u].first + di;
                if(graph[u][i].first){
                //    cout << "aqui? "<< to <<endl;
                    if(!dist[to].second){
                        ++used;
                  //      cout << "paso? "<< to<< endl;
                    }
                    dist[to].second = true;
                }
                else{
                    if(dist[to].second)
                        --used;
                    dist[to].second = false;
                }
                q.push(make_pair(dist[to].first,to));
            }
            else if(dist[u].first + di == dist[to].first && !graph[u][i].first){
                if(dist[to].second)
                    --used;
                dist[to].second = false;
            }
        }
    }
    cout << k - used << endl;
    return 0;
}