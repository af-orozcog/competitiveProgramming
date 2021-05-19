#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int gcd(ll a, ll b){
    return b == 0? a: gcd(b,a%b);
}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        ll n,p;
        scanf(" %lld %lld",&n,&p);
        ll nums[n];
        priority_queue<pl> q;
        for(int i = 0; i < n;++i) {
            scanf(" %lld",&nums[i]);
            q.push({-nums[i],-i});
        }
        vector<bool> marked(n,0);
        ll ans = 0;
        while(q.size()){
            pi see = q.top();
            ll val = -see.first, from = -see.second;
            q.pop();
            if(val >= p) break;
            if(marked[from]) continue;
            for(ll i = from+1; i < n;++i){
                if(marked[i]) break;
                else if(nums[i]% val == 0){
                    ans += val;
                    marked[i] = 1;
                    marked[from] = 1;
                }
            }
            for(ll i = from-1; i > -1;--i){
                if(marked[i]) break;
                else if(nums[i]% val == 0){
                    ans += val;
                    marked[i] = 1;
                    marked[from] = 1;
                }
            }
        }
        ll con = 0;
        for(int i = 0; i < n;++i)
            if(!marked[i]) ++con;
        if(con == n) ans += (ll)(con-1)*(ll)p;
        else ans += (ll)con*(ll)p;
        printf("%lld\n",ans);
    }
    return 0;
}
