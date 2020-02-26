#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,m;
        scanf(" %d %d",&n,&m);
        char ar[n+1];
        vector<ll> dp(n,0);
        scanf(" %s",ar);
        while(m--){
            int p; scanf(" %d",&p);
            ++dp[0];--dp[p];
        }
        vector<ll> ans(26,0);
        ll sum = 0;
        for(int i = 0; i < n;++i){
            sum += dp[i];
            ans[ar[i]-'a'] += sum;
        }
        for(int i = 0; i < n;++i)
            ++ans[ar[i]-'a'];
        for(auto va: ans)
            printf("%d ",va);
        puts("");
    }
    return 0;
}
