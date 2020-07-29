#include<bits/stdc++.h>
using namespace std;

bool bigger(vector<int> x, vector<int> y){
    reverse(x.begin(),x.end());
    reverse(y.begin(),y.end());
    x.push_back(-1);
    t.push_back(-1);
    for(int i = 0; i < x.size();++i){
        if(x[i] < y[i]) return 0;
    }
    return 1;
}


int main(){
    int t;
    scanf(" %d",&t);
    int cas = 1;
    while(t--){
        int n,k,p;
        scanf(" %d %d %d",&n,&k,&p);
        vector<int> stacks(k)[n];
        for(int i = 0; i < n;++i){
            for(int j = 0; j < k;++j)
                scanf(" %d",&stacks[i][j]);
            reverse(stacks[i].begin(),stacks[i].end());
        }
        int ans = 0;
        while(p--){
            int who;
            int keep = 1;
            for(int i = 0; i < n && keep;++i){
                who = i;
                keep = 0;
                for(int j = 0; j < n && !keep;++j){
                    if(!bigger(stacks[i],stacks[j]))
                        keep = 1;
                }
            }
            ans += bigger[who].back();
            biggers[who].pop_back();
        }
        printf("Case %d: %d",cas++,ans);
    }
    return 0;
}
