#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,k;
        scanf(" %d %d",&n,&k);
        int nums[k];
        for(int i = 1; i <= k;++i)
            nums[i-1] = i;
        int dif = n-k;
        while(dif--)
            next_permutation(nums,nums+k);
        for(int i = 0; i < k;++i)
            printf("%d ",nums[i]);
        puts("");
    }
    return 0;
}
