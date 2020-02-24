#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef pair<int,int> pi;

int c[100000],marked[100000];

int main(){
    int n,m;
    scanf(" %d %d",&n,&m);
    map<int,set<int>> fr;
    for(int i = 0; i < n;++i){
        scanf(" %d",&c[i]);
        fr[c[i]].insert(c[i]);
    }
    vector<vector<int>> graph(n);
    while(m--){
        int a,b; scanf(" %d %d",&a,&b);
        --a,--b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    for(int j = 0; j < n;++j){
        if(marked[j]) continue;
        queue<int> q;
        q.push(j);
        marked[j] = 1;
        while(q.size()){
            int f1 = q.front(); q.pop();
            for(int i = 0; i < graph[f1].size();++i){
                fr[c[f1]].insert(c[graph[f1][i]]);
                if(!marked[graph[f1][i]]){
                    q.push(graph[f1][i]);
                    marked[graph[f1][i]] = 1;
                }
            }
        }
    }
    int ans = -1,who = 10000000;
    for(auto &va:fr){
        fr[va.first].erase(va.first);
        if((int)va.second.size() > ans){
            ans = va.second.size();
            who = va.first;
        }
    }
    printf("%d\n",who);
    return 0;
}
