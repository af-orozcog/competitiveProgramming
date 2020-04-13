/**
* Stupid error XD XD
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
ll dp[100005];

int main(){
    int n;
    scanf(" %d",&n);
    //memset(dp,0,sizeof(dp));
    map<pi,ll> fr;
    for(int i = 0; i < n;++i){
        int a,b;ll c;scanf(" %d %d %lld",&a,&b,&c);
        fr[{a,b}] += c;
    }
    pi vals[(int)fr.size()];
    int j = 0;
    for(auto i = fr.begin(); i != fr.end();++i)
        vals[j++] = {(*i).first.first,(*i).first.second};
    int siz = fr.size();
    dp[siz-1] = fr[vals[siz-1]];
    for(int i = siz-2; i > -1;--i){
        pi look = {vals[i].first + 1,vals[i].second+1};
        int index = lower_bound(vals,vals+siz,look)-vals;
        if(index == siz) dp[i] = max(fr[vals[i]],dp[i]);
        else dp[i] = max(fr[vals[i]] + dp[index],dp[i]);
        dp[i] = max(dp[i],dp[i+1]);
    }
    printf("%lld\n",dp[0]);
    return 0;
}
