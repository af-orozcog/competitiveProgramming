#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,x;
        scanf(" %d %d",&n,&x);
        int nums[n];
        int sum = 0;
        for(int i = 0; i < n;++i){
            scanf(" %d",&nums[i]);
            sum += nums[i];
        }
        if(sum % x != 0)
            printf("%d\n",n);
        else{
            int smal = -1;
            for(int i = 0; i < n;++i)
                if(nums[i] % x != 0) smal = max(smal,max(i,n-1-i));
            printf("%d\n",smal);
        }
    }
    return 0;
}
