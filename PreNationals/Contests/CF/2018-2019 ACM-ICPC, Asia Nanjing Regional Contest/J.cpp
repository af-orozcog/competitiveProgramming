#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAX = 1000001;
vector<int> facto;

void sett(){
    facto.resize(MAX,-1);
    for(ll i = 2; i < MAX;++i){
        if(facto[i] == -1){
            facto[i] = i;
            for(ll j = i*i; j < MAX;j+=i) facto[j] = (int)i;
        }
    }
}


int main(){
    sett();
    int n;
    scanf(" %d",&n);
    int nums[n];
    for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
    map<int,int> mp;
    ll ans = 0;
    for(int i = 0; i < n;++i){
        int temp = nums[i];
        set<int> seen;
        while(temp != 1){
            if(!seen.count(facto[temp])){
                seen.insert(facto[temp]);
                int left;
                if(!mp.count(facto[temp])) left = -1;
                else left = mp[facto[temp]];
                ans += (ll)(n-1-i)*(ll)(i-mp[facto[temp]]);
                mp[facto[temp]] = i;
            }
            temp /= facto[temp];
        }
    }
    printf("%lld\n",ans);
    return 0;
}
