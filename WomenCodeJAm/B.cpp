#include<bits/stdc++.h>
using namespace std;

bool valid(int ar[],int n){
    for(int i = 0; i < n-(n&1);i+=2)
        if(ar[i] == ar[i+1])return 0;
    return 1;
}

int main(){
    int t;
    scanf(" %d",&t);
    for(int d = 0; d < t;++d){
        int n;
        scanf(" %d",&n);
        char ans[n];
        int nums[n];
        for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
        int marked[n];
        memset(marked,-1,sizeof(marked));
        if(n&1){
            marked[nums[0]-1] = 0;
            if((nums[0]-1)&1 && nums[0] < n)
                marked[nums[0]] = 1;
            else if(!((nums[0]-1)&1) && nums[0]-1 != 0)
                marked[nums[0]-2] = 1;
            for(int i = 1, j = 0; i < n;i+=2, j = (j+1)&1){
                int re1 = nums[i]-1, re2 = nums[i+1]-1;
                int
                if(marked[re1]!= -1 && marked[re2] != -1)
            }
        }
    }
    return 0;
}
