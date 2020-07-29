#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        priority_queue<ll> q;
        for(int i = 0; i < n;++i){
            ll va;
            scanf(" %lld",&va);
            q.push(-va);
        }
        ll ans = 0;
        while((int)q.size() > 1){
            ll one = q.top();
            q.pop();
            ll two = q.top();
            q.pop();
            ans += -1ll*(one+two);
            q.push(one+two);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
