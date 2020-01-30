#include<bits/stdc++.h>
#define ll long long

using namespace std;
ll N[3*100000];

bool comp(pair<int,int> a, pair<int,int> b){
    return a.first < b.first;
}

int main(){
    int n,d,a;
    scanf(" %d %d %d",&n,&d,&a);
    pair<int,int> ar[n];
    for(int i = 0; i < n;++i) scanf(" %d %d",&ar[i].first,&ar[i].second);
    sort(ar,ar+n,comp);
    ll ans = 0;
    ll cum = 0;
    for(int i = 0; i < n;++i){
        cum += N[i];
        if(ar[i].second + cum <= 0) continue;
        pair<int,int> look = {ar[i].first+(d<<1),0};
        int to = lower_bound(ar+i,ar+n,look,comp)-ar;
        if(to != n && ar[to].first == look.first) ++to;
        ll temp = ar[i].second + cum;
        ll mul = temp /(ll)a;
        if(temp %(ll)a) ++mul;
        cum -= mul*(ll)a;
        N[to] += mul*(ll)a;
        ans += mul;
    }
    printf("%lld\n",ans);
    return 0;
}
