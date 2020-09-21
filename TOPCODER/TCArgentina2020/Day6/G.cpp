#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,int> pi;

int main(){
    int n,m,k;
    scanf(" %d %d %d",&n,&m,&k);
    ll cost[n];
    for(int i = 0; i < n;++i)
        scanf(" %lld",&cost[i]);
    int siz1,siz2;
    scanf(" %d",&siz1);
    set<pi> seen;
    for(int i = 0; i < siz1;++i){
        int temp; scanf(" %d",&temp);
        --temp;
        seen.insert({cost[temp],temp});
    }
    scanf(" %d",&siz2);
    for(int i = 0; i < siz2;++i){
        int temp; scanf(" %d",&temp);
        --temp;
        seen.insert({cost[temp],temp});
    }
    vector<ll> temp;
    vector<ll> temp2;
    for(int i = 0; i < n;++i){
        if(seen.count({cost[i],i}))
            temp.push_back(cost[i]);
        else
            temp2.push_back(cost[i]);
    }
    sort(temp.begin(),temp.end());
    sort(temp2.begin(),temp2.end());
    for(int i = 1; i < temp.size();++i)
        temp[i] += temp[i-1];
    for(int i = 1; i < temp2.size();++i)
        temp2[i] += temp2[i-1];
    if((int)temp.size() < k){puts("-1");return 0;}
    int i = 0,j = -1;
    i = min((int)temp.size(),m);
    --i;
    ll ans = 10000000000000000ll;
    while(i+1+j+1 < m){
        ++j;
    }
    ll sum = temp[i];
    if(j != -1) sum += temp2[j];
    ans = min(ans,sum);
    while(i >= k){
        --i;++j;
        if(j == (int)temp2.size())break;
        ans = min(ans,temp[i]+temp2[j]);
    }
    printf("%lld\n",ans);
    return 0;
}
