#include<bits/stdc++.h>
using namespace std;

bitset<1001> dp[100];
int visited[100];

bitset<1001> solve(int p, vector<vector<int>> &graph){
    if(visited[p]) return dp[p];
    visited[p] = 1;
    for(int i = 0; i < graph[p].size();++i)
        dp[p] = (dp[p] | solve(graph[p][i],graph));
    return dp[p];
}


int main(){
    int t;
    while(cin >> t && t){
        memset(visited,0,sizeof(visited));
        cin.ignore();
        vector<string> lines(t);
        unordered_map<string,int> dpTr;
        vector<vector<int>> graph(t);
        for(int i = 0; i < t;++i){
            string line;
            getline(cin,line);
            lines[i] = line;
            dp[i].reset();
            string temp = "";
            vector<string> sep;
            for(auto va: lines[i]){
                if(va >= 'a' && va <= 'z') temp += va;
                else sep.push_back(temp);
            }
            dpTr[sep[0]] = i;
        }
        unordered_map<string,int> ids;
        int id = -1;
        for(int i = 0;i < t;++i){
            vector<string> sep;
            string temp = "";
            for(auto va: lines[i]){
                if(va >= 'a' && va <= 'z') temp += va;
                else sep.push_back(temp),temp = "";
            }
            for(int j = 1; j < sep.size();++j){
                if(!ids.count(sep[j]) && !dpTr.count(sep[j])){
                    ids[sep[j]] = ++id;dp[i][ids[sep[j]]] = 1;
                }
                else if(dpTr.count(sep[j]))
                    graph[i].push_back(dpTr[sep[j]]);
                else dp[i][ids[sep[j]]] = 1;
            }
        }
        solve(0,graph);
        printf("%d\n",(int)dp[0].count());
    }
    return 0;
}
