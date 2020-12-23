#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int nums[3];
        scanf(" %d %d %d",&nums[0],&nums[1],&nums[2]);
        int di = (nums[0]+nums[1]+nums[2])/9;
        if((nums[0]+nums[1]+nums[2])%9 == 0 && nums[0] >= di && nums[1] >= di && nums[2] >= di)
            puts("YES");
        else puts("NO");
    }
    return 0;
}
