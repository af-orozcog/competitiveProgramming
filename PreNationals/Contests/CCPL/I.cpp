#include<bits/stdc++.h>
using namespace std;


int dp[15][(1<<15)];
vector<vector<int>> g;
int target;
int n,m;

int go(int p, int mask){
    if(dp[p][mask] != -1)
        return dp[p][mask];
    if(mask == (1<<n)-1 && p == target)
        return 1;
    int ans = 0;
    for(auto adj:g[p]){
        if((mask & (1<<adj)) == 0)
            ans = ans | go(adj,mask | (1<<adj));
    }
    return dp[p][mask] = ans;
}

vector<char> toShow;
vector<char> letters;

void getAnswer(int p, int mask){
    toShow.push_back(letters[p]);
    if(mask == (1<<n)-1) return;
    for(auto adj:g[p]){
        if(dp[adj][mask|(1<<adj)] && (mask & (1<<adj)) == 0){
            getAnswer(adj,mask|(1<<adj));
            break;
        }
    }
}

int main(){
    int t;
    scanf(" %d",&t);
    int cas = 1;
    while(t--){
        memset(dp,-1,sizeof(dp));
        toShow.clear();
        scanf(" %d %d",&n,&m);
        g.clear();
        g.resize(n);
        letters.clear();
        letters.resize(n);
        for(int i = 0; i < n;++i)
            scanf(" %c",&letters[i]);
        char to = letters.back();
        char from = letters[0];
        sort(letters.begin(),letters.end());
        target = lower_bound(letters.begin(),letters.end(),to)-letters.begin();
        while(m--){
            char a,b;
            scanf(" %c %c",&a,&b);
            int an = lower_bound(letters.begin(),letters.end(),a)-letters.begin();
            int bn = lower_bound(letters.begin(),letters.end(),b)-letters.begin();
            g[an].push_back(bn);
            g[bn].push_back(an);
        }
        for(int i = 0; i < n;++i)
            sort(g[i].begin(),g[i].end());
        int start = lower_bound(letters.begin(),letters.end(),from)-letters.begin();
        printf("Case %d: ",cas++);
        if(go(start,1<<start)){
            getAnswer(start,1<<start);
            for(auto va:toShow)
                printf("%c",va);
        }
        else
            printf("impossible");
        puts("");
    }
    return 0;
}
