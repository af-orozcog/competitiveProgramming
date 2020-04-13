#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dp1[500005];
ll dp2[500005];
int id = -1;
const int N = (1e5)+3;  // limit for array size
int n;  // array size
ll t[2 * N];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) {
      t[i] = min(t[i<<1],t[i<<1|1]);
      ll va =  t[i<<1];
      ll va2 = t[i<<1|1];
  }
}

void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = min(t[p],t[p^1]);
}

ll query(int l, int r,ll ini) {  // sum on interval [l, r)
  ll res = ini;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = min(res,t[l++]);
    if (r&1) res = min(res,t[--r]);
  }
  return res;
}


int main(){
    scanf(" %d",&n);
    ll nums[n];
    map<ll,int> dif;
    for(int i = 0; i < n;++i){
        scanf(" %lld",&nums[i]);
        dif[nums[i]] = 0;
    }
    for(auto &va:dif)
        va.second = ++id;
    for(int i = 0; i < 2 * N;++i)
        t[i] = 1;
    build();
    for(int i = 0; i < n;++i){
        dp1[i] += nums[i];
        if(dif[nums[i]] == 0){
            modify(dif[nums[i]],-i);
            dp1[i] += nums[i]*(ll)i;continue;
        }
        int va = query(0,dif[nums[i]],1);
        if(va > 0) dp1[i] += nums[i]*(ll)i;
        else{
            va = -va;
            dp1[i] += nums[i]*(ll)(i-va-1);
            dp1[i] += dp1[va];
        }
       modify(dif[nums[i]],-i);
    }
    for(int i = 0; i < 2 * N;++i)
        t[i] = 1000000;
    build();
    int va = query(1,4,1000000);
    for(int i = n-1; i > -1;--i){
        dp2[i] += nums[i];
        if(dif[nums[i]] == 0){
            modify(dif[nums[i]],i);
            dp2[i] += nums[i]*(ll)(n-i-1);continue;
        }
        int va = query(0,dif[nums[i]],1000000);
        if(va == 1000000) dp2[i] += nums[i]*(ll)(n-i-1);
        else{
            dp2[i] += nums[i]*(ll)(va-1-i);
            dp2[i] += dp2[va];
        }
       modify(dif[nums[i]],i);
    }
    ll ma = 0, who;
    for(int i = 0; i < n;++i){
        if(dp1[i]+dp2[i]-nums[i] > ma) ma = dp1[i]+dp2[i]-nums[i],who = i;
    }
    for(int i = who+1; i < n;++i)
        nums[i] = min(nums[i],nums[i-1]);
    for(int i = who-1; i > -1;--i)
        nums[i] = min(nums[i],nums[i+1]);
    for(int i = 0; i < n;++i) printf("%lld ",nums[i]);
    puts("");
    return 0;
}
