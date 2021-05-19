#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,k;
        scanf(" %d %d",&n,&k);
        int nums[n];
        for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
        int i = 0;
        while(i != n-1 && k){
            if(nums[i] == 0){
                ++i;continue;
            }
            --nums[i];
            ++nums[n-1];
            --k;
        }
        for(int i = 0; i < n;++i) printf("%d ",nums[i]);
        puts("");
    }
    return 0;
}
