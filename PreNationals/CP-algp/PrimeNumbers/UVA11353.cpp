#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;

bitset<2000001> posi;
vector<int> d(2000001,-1);

int primeDivisors(int val){
    int ans = 0;
    while(val != 1){
        ++ans;
        val /= d[val];
    }
    return ans;
}

void init(){
    posi.set();
    posi[0] = posi[1] = 0;
    for(ll i = 2; i < 2000001;++i){
        if(posi[i]){
            d[i] = i;
            for(ll j = i*i; j < 2000001;j+=i){
                posi[j] = 0;
                if(d[j] == -1)
                    d[j] = i;
            }
        }
    }
}

int main(){
    init();
    vector<pi> nums;
    nums.push_back({1,1});
    for(int i = 2; i < 2000001;++i)
        nums.push_back({primeDivisors(i),i});
    sort(nums.begin(),nums.end());
    int n;
    int cas = 1;
    while(scanf(" %d",&n) && n){
        printf("Case %d: %d\n",cas++,nums[n-1].second);
    }
    return 0;
}
