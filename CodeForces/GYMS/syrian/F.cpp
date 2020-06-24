#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        int nums[n];
        for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
        sort(nums,nums+n);
        int penalty = 0;
        int time = 0;
        int how = 0;
        for(int i = 0; i < n && time < 301;++i){
            time += nums[i];
            if(time < 301)
                ++how,penalty += time;
        }
        printf("%d %d\n",how,penalty);
    }
    return 0;
}
