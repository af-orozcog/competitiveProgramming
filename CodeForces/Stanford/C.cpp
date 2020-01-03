#include<bits/stdc++.h>
using namespace std;

vector<int> added;
vector<int> cycle;
void dfs1(int p, vector<vector<pair<int,int>>> &graph,vector<int> &marked, int dad, map<int,int> &no1,map<int,int> &no2){
    no1[added.size()] = p;
    marked[p] = 1;
    for(int i = 0; i < graph[p].size();++i){
        if(graph[p][i].first == dad) continue;
        if(!marked[graph[p][i]].first){added.push_back(added.back()+graph[p][i].second);dfs(graph[p][i].first,graph,marked,p);}
        else if(marked[graph[p][i]] == 1){
            no2[graph[p][i]] = 0;
            while(added.back() != graph[p][i].first){
                no2[added.back()] =
                marked[added.back()] = 2;
                cycle.push_back(added.back());
                added.pop_back();
            }

        }
    }
}

int main(){
    int t;
    while(scanf(" %d",&t) && t){
        vector<vector<pair<int,int>>> graph(t);
        set<int> lel;
        for(int i = 0; i < n;++i){
            int a,b,c;
            scanf(" %d %d %d",&a,&b,&c);
            graph[a].push_back({b,c});
            graph[b].push_back({a,c});
            if(graph[a].size() == 1) lel.insert(a);
            else lel.erase(a);
            if(graph[b].size() == 1) lel.insert(b);
            else lel.erase(b);
        }
        dfs((*lel.begin()));
    }
}
