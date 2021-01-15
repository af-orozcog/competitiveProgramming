#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;

int main(){
    int t;
    scanf(" %d",&t);
    for(int i = 0; i < t;++i){
        int n;
        scanf(" %d",&n);
        int nums[n];
        vector<vector<int>> g;
        for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
        int counter = 0;
        map<pi,int> tr1;
        map<int,pi> tr2;
        for(int i = 0; i < n;++i)
            for(int j = 0; j <= nums[i];++j){
                tr1[{i,j}] = counter++;
                tr2[counter-1] = {i,j};
            }
        g.resize(tr1.size());
        for(int i = 0; i < n;++i){
            for(int j = 0; j <= nums[i];++j){
                if(j == 0 && i != 0)
                    g[tr1[{i,j}]].push_back(tr1[{i-1,nums[i-1]}]);
                if(j == nums[i] && i != n-1)
                    g[tr1[{i,j}]].push_back(tr1[{i+1,0}]);
                if(i != 0)
                    g[tr1[{i,j}]].push_back(tr1[{i-1,min(nums[i-1],j)}]);
                if(i != n-1)
                    g[tr1[{i,j}]].push_back(tr1[{i+1,min(nums[i+1],j)}]);
                if(j != nums[i])
                    g[tr1[{i,j}]].push_back(tr1[{i,j+1}]);
                if(j != 0)
                    g[tr1[{i,j}]].push_back(tr1[{i,j-1}]);
            }
        }
        int rs,cs,rf,cf;
        scanf(" %d %d %d %d",&rs,&cs,&rf,&cf);
        --rs,--rf;
        int ans = INT_MAX;
        queue<pi> q;
        q.push({tr1[{rs,cs}],0});
        set<int> seen;
        seen.insert(tr1[{rs,cs}]);
        while(1){
            pi dad = q.front();
            q.pop();
            if(tr2[dad.first].first == rf && tr2[dad.first].second == cf){
                ans = dad.second;
                break;
            }
            for(auto adj:g[dad.first]){
                if(!seen.count(adj)){
                    q.push({adj,dad.second+1});
                    seen.insert(adj);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
