#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> &nums){
    int sz = (int)nums.size()/3;
    for(int i = 0; i < sz;++i)
        if(nums[i]+nums[i+sz] != nums[i+sz+sz])
            return 0;
    return 1;
}


int main(){
    int n;
    scanf(" %d",&n);
    if(n == 1 || n > 3)
        puts("Yes");
    else puts("No");
    return 0;
}
