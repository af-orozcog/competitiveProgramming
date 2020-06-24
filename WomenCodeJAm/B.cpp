#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    int cas = 1;
    while(t--){
        int n;
        scanf(" %d",&n);
        int nums[n];
        for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
        reverse(nums,nums+n);
        vector<int> ar(n+2,-1);
        for(int i = 0; i < n;i+=2){
            if(nums[i]%2 == 1 && ar[nums[i]+1] != -1)
                ar[nums[i]] = (ar[nums[i]+1]+1)%2;
            else if(nums[i]%2 == 0 && ar[nums[i]-1] != -1)
                ar[nums[i]] = (ar[nums[i]-1]+1)%2;
            else{
                if(i != n-1){
                    if(nums[i+1]%2 == 1 && ar[nums[i+1]+1] != -1)
                        ar[nums[i+1]] = (ar[nums[i+1]+1]+1)%2;
                    else if(nums[i+1]%2 == 0 && ar[nums[i+1]-1] != -1)
                        ar[nums[i+1]] = (ar[nums[i+1]-1]+1)%2;
                    else ar[nums[i+1]] = 1;
                    ar[nums[i]] = (ar[nums[i+1]]+1)%2;
                }
                else ar[nums[i]] = 1;
            }
            if(i != n-1)
                ar[nums[i+1]] = (ar[nums[i]]+1)%2;
        }
        printf("Case #%d: ",cas++);
        for(int i = 1; i <= n;++i){
            if(ar[i] == 1) printf("L");
            else printf("R");
        }
        puts("");
    }
    return 0;
}
