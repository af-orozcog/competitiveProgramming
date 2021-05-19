#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAX = 1e6+3;

ll BIT[2][MAX];

void add(int who, int pos, ll val){
    while(pos < MAX){
        BIT[who][pos] += val;
        pos += (pos&(-pos));
    }
}

ll query(int who, int pos){
    ll ans = 0;
    while(pos){
        ans += BIT[who][pos];
        pos -= (pos&(-pos));
    }
    return ans;
}

int main(){
    int n;
    scanf(" %d",&n);
    int nums[n];
    set<int> uni;
    for(int i = 0; i < n;++i){
        scanf(" %d",&nums[i]);
        uni.insert(nums[i]);
    }
    map<int,int> id;
    int ne = 1;
    for(auto val:uni){
        id[val] = ne++;
    }
    ll ans = 0;
    for(int i = n-1; i > -1;--i){
        ans += query(1,id[nums[i]]-1);
        add(1,id[nums[i]],query(0,id[nums[i]]-1));
        add(0,id[nums[i]],1);
    }

    printf("%lld\n",ans);
    return 0;
}
