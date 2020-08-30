#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n,m;
    scanf(" %d %d",&n,&m);
    priority_queue<ll> q1;
    priority_queue<ll> q2;
    for(int i = 0; i < m;++i){
        ll va;
        scanf(" %lld",&va);
        q1.push(va);
        q2.push(-va);
    }
    ll ans1 =0, ans2 = 0;
    for(int i = 0; i < n;++i){
        ll add = q1.top();
        q1.pop();
        ans1 += add;
        --add;
        if(add)
            q1.push(add);
    }
    for(int i = 0; i < n;++i){
        ll add = -q2.top();
        q2.pop();
        ans2 += add;
        --add;
        if(add)
            q2.push(-add);
    }
    printf("%lld %lld\n",ans1,ans2);
    return 0;
}
