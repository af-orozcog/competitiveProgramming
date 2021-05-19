#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf(" %d",&n);
    int nums[n];
    for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);

    int lo = 0,hi = n-1;
    while(lo < n-1 && nums[lo] < nums[lo+1]) ++lo;
    while(hi > 0 && nums[hi] < nums[hi-1]) --hi;
    while(lo < hi && nums[lo] == nums[hi]) --hi;
    if(lo >= hi) puts("YES");
    else puts("NO");
    return 0;
}
