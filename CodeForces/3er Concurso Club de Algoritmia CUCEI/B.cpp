#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll vals[10];
int siz;

int main(){
    scanf(" %d",&siz);
    for(int i = 0; i < siz;++i) scanf(" %lld",&vals[i]);
    set<pair<ll,pair<ll,ll>>> show;
    vector<int> yei(siz+1,0);
    while(1){
        if(yei[siz])break;
        ll add1 = 0,add2 = 0,add3 = 0;
        yei[0]+=1;
        int j = 0;
        int digi;
        if(yei[0]>3) digi = 1,yei[0] = 0;
        else digi = 0;
        while(j < siz+1 && digi){
            yei[j] += 1;
            if(yei[j] > 3) yei[j] = 0,digi = 1;
            else digi = 0;
            ++j;
        }
        for(int i = 0; i < siz;++i){
            if(yei[i] == 0) add1 = vals[i];
            if(yei[i] == 1) add2 = vals[i];
            if(yei[i] == 2) add3 = vals[i];
        }
        if(add1 == add2 || add1 == add3 || add3 == add2) continue;
        ll mi = min(add1,min(add2,add3));
        ll ma = max(add1,max(add2,add3));
        ll mid = add1+add2+add3-mi-ma;
        show.insert({mi,{mid,ma}});
    }
    for(auto va: show)
        printf("%lld %lld %lld\n",va.first,va.second.first,va.second.second);
    return 0;
}
