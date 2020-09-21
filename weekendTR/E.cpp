#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    scanf(" %d %d",&n,&m);
    vector<vector<int>> graph(n);
    for(int i = 1; i < n;++i){
        int a,b;
        scanf(" %d %d",&a,&b);
        --a,--b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> dist(n,-1);
    vector<int> check(n,0);
    queue<int> q;
    for(int i = 0; i < m;++i){
        int val;
        scanf(" %d",&val);
        --val;
        q.push(val);
        dist[val] = 0;
        check[val] = 1;
    }
    while(q.size()){
        int dad = q.front();
        q.pop();
        for(auto va:graph[dad]){
            if(dist[va] == -1){
                q.push(va);
                dist[va] = dist[dad]+1;
                check[va] += check[dad];
            }
            else if(dist[dad]+1 == dist[va])
                check[va] += check[dad];
        }
    }
    int co = 0;
    int ans;
    for(int i = 0; i < check.size();++i){
        if(check[i] == m){
            ++co;
            ans = i+1;
        }
    }
    if(!co) puts("NO");
    else{
        puts("YES");
        printf("%d\n",ans);
    }
    return 0;
}
