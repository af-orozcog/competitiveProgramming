#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll distUP[100007];
ll distDO[100007];

const ll multy = 1;

int main(){
    //ll see = 10000000000000000ll;
    //printf("%lld\n",see<<1);
    ll x,y,n;
    scanf(" %lld %lld %lld",&x,&y,&n);
    map<ll,ll> frMA,frMI;
    map<ll,ll> mim;
    map<ll,ll> mam;
    for(int i = 0; i < n;++i){
        ll x1,y1;
        scanf(" %lld %lld",&x1,&y1);
        mam[x1] = max(mam[x1],y1);
        if(mim.count(x1)) mim[x1] = min(mim[x1],y1);
        else mim[x1] = y1;
    }
    for(auto va:mam)
        ++frMA[va.second];
    for(auto va:mim)
        ++frMI[va.second];
    ll beh = frMI[0];
    for(ll i = 1; i < y;++i){
        distUP[i] = distUP[i-1] + beh;
        beh += frMI[i];
    }
    beh = 0;
    for(ll i = y-1; i > -1ll;--i){
        distDO[i] = distDO[i+1]+beh;
        beh += frMA[i];
    }
    ll mi = 10000000000000000ll;
    for(int i = 0; i < y;++i)
        mi = min(distDO[i]+distUP[i],mi);
    printf("%lld\n",(mi<<1)+(x-1ll));
    return 0;
}
