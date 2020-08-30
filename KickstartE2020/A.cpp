#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;

int main(){
    int t;
    scanf(" %d",&t);
    int cas = 1;
    while(t--){
        int n;
        scanf(" %d",&n);
        int nums[n];
        for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
        int ans = 2;
        int lastDif = nums[0]-nums[1];
        int temp = 2;
        for(int i = 1; i < n-1;++i){
            if(nums[i]-nums[i+1] == lastDif)
                ++temp;
            else
                temp = 2,lastDif = nums[i]-nums[i+1];
            ans = max(ans,temp);
        }
        printf("Case #%d: %d\n",cas++,ans);
    }
    return 0;
}
