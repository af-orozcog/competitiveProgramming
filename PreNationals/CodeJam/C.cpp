#include<bits/stdc++.h>
using namespace std;

int operations(vector<int> nums, int n){
    int ans = 0;
    for(int i = 0; i < n-1;++i){
        int where = i;
        for(int j = where; j < n;++j){
            if(nums[j] < nums[where])
                where = j;
        }
        ans += (where-i+1);
        reverse(nums.begin()+i,nums.begin()+where+1);
    }
    return ans;
}

int main(){
    int t;
    scanf(" %d",&t);
    int cas = 1;
    while(t--){
        int n,c;
        scanf(" %d %d",&n,&c);
        vector<int> nums(n);
        for(int i = 0; i < n;++i) nums[i] = i+1;
        bool ans = 0;
        do{
            if(operations(nums,n) == c){
                ans = 1;
                break;
            }
        }while(next_permutation(nums.begin(),nums.end()));

        printf("Case #%d:",cas++);
        if(!ans) printf(" IMPOSSIBLE");
        else{
            for(int i = 0; i < n;++i)
                printf(" %d",nums[i]);
        }
        puts("");
    }
    return 0;
}
