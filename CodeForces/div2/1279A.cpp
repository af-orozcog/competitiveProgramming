#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int nums[3];
        cin >> nums[0] >> nums[1] >> nums[2];
        sort(nums,nums+3);
        if(nums[2] - (nums[0]+nums[1]) <= 1) puts("Yes");
        else puts("No");
    }
    return 0;
}
