/**
* R.I.P KOBE
*/
#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;scanf(" %d",&n);
        n = (n <<1);
        int nums[n];
        for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
        sort(nums,nums+n);
        printf("%d\n",abs(nums[n>>1]-nums[(n>>1)-1]));
    }
    return 0;
}
