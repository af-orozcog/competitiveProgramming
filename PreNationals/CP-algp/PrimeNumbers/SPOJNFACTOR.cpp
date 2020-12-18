#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> posi(1000001,1);

void init(){
    posi[0] = posi[1] = 0;
    for(int i = 2; i < 1000001;++i){
        if(posi[i] == 1){
            for(int j = i*2; j < 1000001;j+=i) ++posi[j];
        }
    }
}


int main(){
    int t;
    init();
    scanf(" %d",&t);
    unordered_map<int,vector<int>> dp;
    dp[0].push_back(1);
    for(int i = 2; i < 1000001;++i){
        if(posi[i] == 1)
            dp[posi[i]].push_back(i);
        else
            dp[posi[i]-1].push_back(i);
    }
    while(t--){
        int l,r,n;
        scanf(" %d %d %d",&l,&r,&n);
        int index1 = lower_bound(dp[n].begin(),dp[n].end(),l)-dp[n].begin();
        int index2 = upper_bound(dp[n].begin(),dp[n].end(),r)-dp[n].begin();
        printf("%d\n",index2-index1);
    }
    return 0;
}
