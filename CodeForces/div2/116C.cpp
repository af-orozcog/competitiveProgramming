#include<iostream>
#include<vector>
#define max(x,y)(x > y?x:y)

using namespace std;

int maxDepth(int s,vector<vector<int>> &graph){
    int ans = 1;
    int sum = 0;
    for(int i = 0; i < graph[s].size();++i){
        sum = max(sum,maxDepth(graph[s][i],graph));
    }
    return sum + ans;
}

int main(){
    int n;
    scanf(" %d",&n);
    vector<vector<int>> graph(n);
    vector<int> unique;
    for(int i = 0; i < n;++i){
        int a;
        scanf(" %d",&a);
        if(a == -1){
            unique.push_back(i);
            continue;
        }
        --a;
        graph[a].push_back(i);
    }
    int ans = 0;
    for(int i = 0; i < unique.size();++i){
        ans = max(ans,maxDepth(unique[i],graph));
    }
    printf("%d\n",ans);
    return 0;
}