#include<bits/stdc++.h>
using namespace std;

int seen[100003];
bool posi = 1;
vector<vector<int>> g;


void dfs(int p, int color){
    seen[p] = color;
    for(auto va:g[p]){
        if(seen[va] == -1)
            dfs(va,(color+1)%2);
        else if(seen[va] == seen[p])
            posi = 0;
    }
}

int main(){
    memset(seen,-1,sizeof(seen));
    int n,m;
    scanf(" %d %d",&n,&m);
    g.resize(n);
    for(int i = 0; i < m;++i){
        int a,b;
        scanf(" %d %d",&a,&b);
        --a,--b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i = 0; i < n;++i){
        if(seen[i] == -1)
            dfs(i,0);
    }
    vector<vector<int>> ans(2);
    if(!posi){ puts("-1"); return 0;}
    for(int i = 0; i < n && posi;++i){
        ans[seen[i]].push_back(i+1);
    }
    for(auto &va:ans){
        cout << va.size() << "\n";
        for(auto ve:va)
            cout << ve << " ";
        cout << "\n";
    }
    return 0;
}
