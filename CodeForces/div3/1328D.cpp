#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        int nums[n];
        int ans[n];
        for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
        int dif = 1;
        int co = 0;
        for(int i = 1; i < n;++i){
            if(nums[i] != nums[i-1])++dif;
            else co = 1;
        }
        if((dif&1) && dif > 1){
            if(co){
                ans[0] = 1;
                for(int i = 1,j = 1; i < n;++i){
                    if(nums[i] == nums[i-1]){
                        if(co) ans[i] = (ans[i-1] == 1?2:1),co = 0;
                        else ans[i] = ans[i-1];
                    }
                    else
                        ans[i] = (ans[i-1] == 1?2:1);
                }
            }
            else{
                ans[0] = 1;
                for(int i = 1,j = 1; i < n-1;++i){
                    if(nums[i] == nums[i-1])
                        ans[i] = ans[i-1];
                    else
                        ans[i] = (ans[i-1] == 1?2:1);
                }
                ans[n-1] = 3;
            }
        }
        else{
             ans[0] = 1;
                for(int i = 1; i < n;++i){
                    if(nums[i] == nums[i-1])
                        ans[i] = ans[i-1];
                    else
                        ans[i] = (ans[i-1] == 1?2:1);
            }
        }
        if(ans[n-1] == 3 && nums[0] == nums[n-1]) ans[n-1] = (ans[n-2] == 1?2:1);
        set<int> see;
        for(int i = 0; i < n;++i) see.insert(ans[i]);
        printf("%d\n",(int)see.size());
        for(int i = 0; i < n;++i) printf("%d ",ans[i]);
        puts("");
    }
}
