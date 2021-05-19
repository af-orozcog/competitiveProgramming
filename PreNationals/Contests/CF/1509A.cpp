#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;


int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        vector<vector<int>> nums(2);
        for(int i = 0; i < n;++i){
            int va; scanf(" %d",&va);
            nums[va&1].push_back(va);
        }
        for(auto va:nums[0]) printf("%d ",va);
        for(auto va:nums[1]) printf("%d ",va);
        puts("");
    }
    return 0;
}
