#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
vector<pi> solution;

bool sol = 0;

void dfs(pi last,set<pi> &ava, set<pi> &used){
    if(sol) return;
    if(ava.size() == used.size()){
        sol = 1; return;
    }
    for(auto va: ava){
        if(used.count(va))continue;
        if(va.first -va.second == last.first-last.second)continue;
        if(va.first + va.second == last.first+last.second) continue;
        if(va.first == last.first || va.second == last.second) continue;
        solution.push_back(va);
        used.insert(va);
        dfs(va,ava,used);
        if(sol) return;
        used.erase(va);
        solution.pop_back();
    }
}


int main(){
    int t;
    scanf(" %d",&t);
    int cas = 1;
    while(t--){
        sol = 0;
        solution.clear();
        int r,c;
        scanf(" %d %d",&r,&c);
        printf("Case #%d: ",cas++);
        set<pi> send,used;
        for(int i = 1; i <= r;++i){
            for(int j = 1; j <= c;++j)
                send.insert({i,j});
        }
        for(auto va: send){
            solution.push_back(va);
            used.insert(va);
            dfs(va,send,used);
            if(sol) break;
            used.erase(va);
            solution.pop_back();
        }
        if(sol){
            puts("POSSIBLE");
            for(auto va:solution) printf("%d %d\n",va.first,va.second);
        }
        else puts("IMPOSSIBLE");
    }
    return 0;
}
