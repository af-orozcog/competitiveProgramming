#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAX = 1e6+2;

int BIT[MAX];

void add(int pos){
    while(pos < MAX){
        ++BIT[pos];
        pos += (pos&(-pos));
    }
}

int query(int pos){
    int ans = 0;
    while(pos){
        ans += BIT[pos];
        pos -= (pos&(-pos));
    }
    return ans;
}

int main(){
    int n;
    scanf(" %d",&n);
    int nums[n];
    for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
    map<int,int> freqL,freqR;
    for(int i = 0; i < n;++i){
        ++freqL[nums[i]];
    }

    ll ans = 0;
    for(int i = n-1;i > 0;--i){
        --freqL[nums[i]];
        add(++freqR[nums[i]]);
        ans += (ll)query(freqL[nums[i-1]]-1);
    }

    printf("%lld\n",ans);
    return 0;
}
