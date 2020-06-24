#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

int main(){
    int nums[31];
    nums[0] = 1;
    for(int i = 1; i < 31;++i)
        nums[i] = nums[i-1]<<1;
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        int a = nums[n];
        int b = 0;
        int ha = n>>1;
        for(int i = 1; i < ha;++i)
            a += nums[i];
        for(int i = ha; i < n;++i)
            b += nums[i];
        printf("%d\n",abs(a-b));
    }
    return 0;
}
