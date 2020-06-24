#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,c;
    scanf(" %d %d",&n,&c);
    int nums[n];
    for(int i = 0; i < n;++i)scanf(" %d",&nums[i]);
    sort(nums,nums+n);
    int needed = 0;
    int i = 0, j = n-1;
    while(i <= j){
        if(nums[i] + nums[j] <= c)
            ++i,--j;
        else
            --j;
        ++needed;
    }
    printf("%d\n",needed);
    return 0;
}
