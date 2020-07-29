#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;

int child[2*100000];
int depth[2*100000];

int dfs(int p, int dad, vector<vector<int>> &graph, int d){
    depth[p] = d;
    int children = 1;
    for(auto va: graph[p])
        if(va != dad)
            children += dfs(va,p,graph,d+1);
    child[p] = children;
    return child[p];
}

int main(){
    int n,k;
    scanf(" %d %d",&n,&k);
    vector<vector<int>> graph(n);
    for(int i = 0; i < n-1;++i){
        int a,b;
        scanf(" %d %d",&a,&b);
        --a,--b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(0,-1,graph,1);
    int see[n];
    for(int i = 0; i < n;++i){
        see[i] = child[i]-depth[i];
        //cout << i << see[i] << "\n";
    }
    sort(see,see+n);
    ll ans = 0;
    reverse(see,see+n);
    for(int i = 0; i < n-k;++i){
        //cout << "wtf " << see[i] << "\n";
        ans += see[i];
    }
    printf("%lld\n",ans);
    return 0;
}
