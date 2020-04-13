#include<bits/stdc++.h>
#define ll long long
#define MAX 1005
using namespace std;

ll bit[1005];
typedef pair<ll,ll> pi;


void update(int x){
    while(x < MAX){
        ++bit[x];
        x += (x&(-x));
    }
}

ll sum(int x){
    ll ans = 0;
    while(x){
        ans += bit[x];
        x -= (x&(-x));
    }
    return ans;
}

int main(){
    freopen("dull.in","r",stdin);
    int t;
    scanf(" %d",&t);
    while(t--){
        memset(bit,0,sizeof(bit));
        ll n,m,k;
        scanf(" %lld %lld %lld",&n,&m,&k);
        pi nums[k];
        set<ll> dif;
        for(int i = 0; i < k;++i){
            scanf(" %lld %lld",&nums[i].first,&nums[i].second);
            dif.insert(nums[i].second);
        }
        sort(nums,nums+k);
        unordered_map<int,int> fr;
        int co = 0;
        for(auto va: dif)
            fr[va] = ++co;
        set<int> seen;
        int last = -1;
        ll rtag=0, rta = 0;
        for(int i = 0; i < k;){
            if(nums[i].first != last){
              rtag +=rta*(nums[i].first-last);
              last = nums[i].first;
              int j = i;
              while(j<k && nums[j].first == nums[i].first){
                seen.insert(nums[j].second);
                update(fr[nums[j].second]);
                ++j;
              }
              i = j;
            }
            int lc = 0, acum = 0; rta= 0;
            for(auto c: seen){
                rta += (c-lc)*acum;
                lc = c;
                acum = sum(fr[c])&1;
                if(!acum)
                    acum = 0;
            }
            rta+=(m+1-lc)*acum;
        }
        rtag +=(1+n-last)*rta;
        ll rtag2 = n*m-rtag;
        printf("%lld %lld\n",rtag, rtag2);
    }
}
