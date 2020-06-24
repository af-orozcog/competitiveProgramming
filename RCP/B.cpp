#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;

vector<int> ans;

int main(){
    int n;
    scanf(" %d",&n);
    set<int> del;
    vector<int> vals(n);
    for(int i = 0; i < n;++i) del.insert(i);
    vector<vector<int>> graph(n);
    vector<int> coun(n,0);
    for(int i = 0; i < n;++i){
        int d;
        scanf(" %d %d",&vals[i],&d);
        while(d--){
            int fr; scanf(" %d",&fr);
            --fr;
            ++coun[fr];
            del.erase(fr);
            graph[i].push_back(fr);
        }
    }
    priority_queue<pair<int,int>> q;
    for(auto va:del)
        q.push({-vals[va],va});
    int t = 0;
    vector<int> marked(n,0);
    while(q.size()){
        pair<int,int> ss = q.top();
        q.pop();
        ans.push_back(ss.second);
        for(auto va:graph[ss.second]){
            ++marked[va];
            if(marked[va] == coun[va])
                q.push({-vals[va],va});
        }
    }
    int anss = 0;
    reverse(ans.begin(),ans.end());
    for(int i = 0; i < ans.size();++i)
        anss = max(anss,vals[ans[i]]+i);
    printf("%d\n",anss);
    return 0;
}
