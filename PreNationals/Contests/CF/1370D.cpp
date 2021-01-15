#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;

bool can(int nums[], int k, int x, int n){
    vector<int> vals;
    for(int i = 0; i < n && vals.size() != k;++i){
        if((int)vals.size() %2 == 0 && nums[i] <= x)
            vals.push_back(nums[i]);
        else if((int)vals.size()%2 == 1)
            vals.push_back(nums[i]);

    }
    return (int)vals.size() == k;
}


int main(){
    int n,k;
    scanf(" %d %d",&n,&k);
    int nums[n];
    for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
    int lo = 1, hi = 1000000000, ans;
    while(lo <= hi){
        int mid = (lo+hi)>>1;
        if(can(nums,k,mid,n))
            ans = mid, hi = mid -1;
        else
            lo = mid + 1;
    }
    printf("%d\n",ans);
    return 0;
}
