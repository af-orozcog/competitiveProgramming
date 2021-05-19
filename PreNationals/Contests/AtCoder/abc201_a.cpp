#include<bits/stdc++.h>
using namespace std;

int main(){
    int nums[3];
    scanf(" %d %d %d",&nums[0],&nums[1],&nums[2]);
    sort(nums,nums+3);
    bool ans = 0;
    do{
        ans = (nums[1]-nums[0] == nums[2]-nums[1]);
    }while(next_permutation(nums,nums+3));
    if(ans) puts("Yes");
    else puts("No");
    return 0;
}
