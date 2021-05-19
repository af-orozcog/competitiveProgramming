#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        vector<vector<int>> nums(2);
        for(int i = 0; i < n;++i){
            int temp;
            scanf(" %d",&temp);
            nums[temp&1].push_back(i+1);
        }
        if(nums[0].size())printf("1\n%d\n",nums[0][0]);
        else if(nums[1].size() > 1) printf("2\n%d %d\n",nums[1][0],nums[1][1]);
        else puts("-1");
    }
    return 0;
}
