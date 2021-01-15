#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,d;
        scanf(" %d %d",&n,&d);
        int nums[n];
        bool posi = 1;
        for(int i = 0; i < n;++i){
            scanf(" %d",&nums[i]);
            posi = posi & (nums[i] <= d);
        }
        for(int i = 0; i < n && !posi;++i){
            for(int j = i+1; j < n && !posi;++j){
                posi = posi | (nums[i]+nums[j] <= d);
            }
        }
        if(posi) puts("YES");
        else puts("NO");
    }
    return 0;
}
