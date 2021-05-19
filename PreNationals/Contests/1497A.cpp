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
        int nums[n];
        for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
        sort(nums,nums+n);
        int left = 0, right = n-1;
        int ans[n];
        for(int i = 0; i < n;++i){
            if(i && nums[i] == nums[i-1]) ans[right--] = nums[i];
            else ans[left++] = nums[i];
        }
        for(int i = 0; i < n;++i) printf("%d ",ans[i]);
        puts("");
    }
    return 0;
}
