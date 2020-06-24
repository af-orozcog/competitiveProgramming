#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,c;
    scanf(" %d %d",&n,&c);
    int nums[n];
    for(int i = 0; i < n;++i)scanf(" %d",&nums[i]);
    sort(nums,nums+n);
    int needed = 0;
    for(int i = 0; i < n;++i){
        if(i != n-1){
            if(nums[i] + nums[i+1] <= c)
                ++needed,++i;
            else{
                needed += n - i;
                break;
            }
        }
        else
            ++needed;
    }
    printf("%d\n",needed);
    return 0;
}
