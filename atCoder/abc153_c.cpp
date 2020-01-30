#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n,k;
    scanf(" %d %d",&n,&k);
    priority_queue<int> q;
    for(int i = 0; i < n;++i){
        int va; scanf(" %d",&va);
        q.push(va);
    }
    ll ans = 0;
    for(int i = 0; i < n;++i){
        int see = q.top();
        q.pop();
        if(k <= 0)ans += (ll)see;
        --k;
    }
    printf("%lld\n",ans);
    return 0;
}
