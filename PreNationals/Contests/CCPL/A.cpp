#include<bits/stdc++.h>
using namespace std;

vector<int> topo;
vector<int> seen(10000,0);

int dfs(int p, vector<vector<int>> &g, int mark = 1){
    seen[p] = mark;
    int ans = 0;
    for(auto adj:g[p])
        if(!seen[adj]){
            ++ans;
            ans += dfs(adj,g);
        }
    return max(ans-1,0);
}

void topoSort(int p, vector<vector<int>> &g){
    seen[p] = 1;
    for(auto adj:g[p])
        if(!seen[adj])
            topoSort(adj,g);
    topo.push_back(p);
}

vector<vector<int>> GInverse(vector<vector<int>> &g){
    vector<vector<int>> answer(g.size());
    for(int i = 0; i < g.size();++i){
        for(auto adj:g[i])
            answer[adj].push_back(i);
    }
    return answer;
}

vector<vector<int>> NoCycles(vector<vector<int>> &g){
    vector<vector<int>> answer = g;
    while(1){
        fill(seen.begin(),seen.end(),0);
        vector<vector<int>> GI = GInverse(answer);
        topo.clear();
        for(int i = 0; i < answer.size();++i)
            if(!seen[i])
                topoSort(i,GI);
        reverse(topo.begin(),topo.end());
        int SCC = 0;
        fill(seen.begin(),seen.end(),0);
        for(auto va:topo){
            if(!seen[va]){
                dfs(va,answer,SCC+1);
                ++SCC;
            }
        }
        if(SCC == answer.size()) break;
        vector<vector<int>> temp(SCC);
        for(int i = 0; i < answer.size();++i){
            for(auto adj:answer[i]){
                if(seen[adj] != seen[i])
                    temp[SCC-seen[i]-1].push_back(SCC-seen[adj]-1);
            }
        }
        answer = temp;
    }
    return answer;
}

int main(){
    int n,m;
    while(scanf(" %d %d",&n,&m) == 2){
        vector<vector<int>> g(n);
        for(int i = 0; i < m;++i){
            int a,b;
            scanf(" %d %d",&a,&b);
            g[a].push_back(b);
        }
        g = NoCycles(g);
        int ans = 0;
        fill(seen.begin(),seen.end(),0);
        for(int i = 0; i < g.size();++i)
            if(!seen[i])
                ans += dfs(i,g);
        printf("%d\n",ans+1);
    }
    return 0;
}
