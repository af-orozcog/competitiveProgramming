#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
// ERROR is because one the same node can be its parent but they are quite far and
// in differente directions of each other
int change;
pi dp[(2*100000)+2];
int dads[(2*100000)+2];
void dfs(int p, int dad,int tag,vector<vector<int>> &graph){
    dp[p] = {dp[dad].first+1,tag};
    int neTag = ((change || (dad == 1 && p != 1))?p:tag);
    if(change || (dad == 1 && p != 1)) dads[neTag] = tag;
    change = 0;
    for(int i = 0; i < graph[p].size();++i)
        if(graph[p][i] != dad){
            if((int)graph[p].size()-1 > 1) change = 1;
            dfs(graph[p][i],p,neTag,graph);
        }
}

bool findDad(int p,unordered_set<int> &posDads){
    posDads.erase(p);
    while(dads[p] != p && posDads.size()){
        p = dads[p];
        posDads.erase(p);
    }
    return (int)posDads.size() == 0;
}

int main(){
    int n,m;
    scanf(" %d %d",&n,&m);
    vector<vector<int>> graph(n+1);
    for(int i = 0; i < n-1;++i){
        int a,b;
        scanf(" %d %d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dads[1] = 1;
    dp[1] = {0,0};
    dfs(1,1,1,graph);
    for(int j = 0; j < m;++j){
       int k;
       scanf(" %d",&k);
       unordered_set<int> posDads;
       int farthest = 0;
       int last;
       for(int i = 0; i < k;++i){
            int va;scanf(" %d",&va);
            posDads.insert(dp[va].second);
            if(dp[va].first > farthest) farthest = dp[va].first, last = dp[va].second;
       }
       if(findDad(last,posDads)) puts("YES");
       else puts("NO");
    }
    return 0;
}
