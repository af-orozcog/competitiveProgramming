#include<bits/stdc++.h>
using namespace std;
vector<int> topo;
vector<vector<int>> g;
vector<int> seen;
void topoSort(int p){
    seen[p] = 1;
    for(auto va:g[p])
        if(!seen[va])
            topoSort(va);
    topo.push_back(p);
}

int fastSum(int n){
    return (n*(n+1))>>1;
}

int main(){
    int n;
    scanf(" %d",&n);
    g.resize(n);
    seen.resize(n,0);
    set<pair<int,int>> see;
    for(int i = 0; i < n;++i)
        for(int j = i+1; j < n;++j)
            see.insert({i,j});
    int to = fastSum(n-1);
    for(int i = 0; i < to-1;++i){
        int a,b;
        scanf(" %d %d",&a,&b);
        --a,--b;
        g[a].push_back(b);
        if(a > b) swap(a,b);
        see.erase({a,b});
    }
    for(int i = 0; i < n;++i)
        if(!seen[i])
            topoSort(i);
    reverse(topo.begin(),topo.end());
    int first = -1;
    pair<int,int> need = *(see.begin());
    for(int i = 0; i < topo.size() && first == -1;++i){
        if(topo[i] == need.first || topo[i] == need.second)
            first = i;
    }
    if(topo[first] == need.second)
        swap(need.first,need.second);
    printf("%d %d\n",need.first+1,need.second+1);
    return 0;
}
