#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    scanf(" %d %d",&n,&m);
    vector<vector<int>> see(m);
    for(int i = 0; i < m;++i){
        int k;
        scanf(" %d",&k);
        for(int j = 0; j < k;++j){
            int va;
            scanf(" %d",&va);
            --va;
            see[i].push_back(va);
        }
    }
    vector<int> p(m,0);
    for(int i = 0; i < m;++i)
        scanf(" %d",&p[i]);
    int ans = 0;
    for(int i = 0; i < (1<<n);++i){
        int temp = i;
        int j = 0;
        set<int> use;
        while(temp){
            if(temp&1)use.insert(j);
            temp >>=1;
            ++j;
        }
        bool add = 1;
        for(int j = 0; j < m && add;++j){
            int val = 0;
            for(auto va:see[j])
                if(use.count(va))
                    ++val;
            if(val%2 != p[j]) add = 0;
        }
        if(add) ++ans;
    }
    printf("%d\n",ans);
    return 0;
}
