#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;scanf(" %d",&n);
        int nums[n];
        int l = -1,r = -1;
        for(int i = 0; i < n;++i){
            scanf(" %d",&nums[i]);
            if(i == 0) continue;
            if(abs(nums[i]-nums[i-1]) >= 2)
                l = i, r = i+1;
        }
        if(l != -1) printf("YES\n%d %d\n",l,r);
        else printf("NO\n");
    }
    return 0;
}
