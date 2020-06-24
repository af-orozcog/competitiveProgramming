#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    scanf(" %d %d",&n,&m);
    vector<int> id(n,-1);
    vector<vector<int>> graph(n);
    while(m--){
        int a,b;
        scanf(" %d %d",&a,&b);
        --a,--b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    set<pair<int,int>> coolSet;
    for(int i = 0; i < n;++i){
        int va;scanf(" %d",&va);
        coolSet.insert({va,i});
    }
    bool posi = 1;
    vector<int> order;
    while(coolSet.size()){
        int lo = coolSet.begin()->first;
        auto it = coolSet.begin();
        vector<pair<int,int>> del;
        while(it != coolSet.end() && it->first == lo && posi){
            int who = it->second;
            vector<int> neig;
            for(auto va: graph[who]){
                if(id[va] != -1)
                    neig.push_back(id[va]);
            }
            neig.push_back(0);
            sort(neig.begin(),neig.end());
            int ne = -1;
            for(int i = 1; i < neig.size() && ne == -1;++i)
                if(neig[i] - neig[i-1] > 1) ne = neig[i-1]+1;
            if(ne == -1)
                ne = neig.back() + 1;
            if(ne != lo) posi = 0;
            del.push_back(*it);
            order.push_back(who+1);
            id[who] = lo;
            ++it;
        }
        if(!posi) break;
        for(auto va:del)
            coolSet.erase(va);
    }
    if(posi)
        for(auto va:order)
            printf("%d ",va);
    else
        printf("-1");
    puts("");
}
