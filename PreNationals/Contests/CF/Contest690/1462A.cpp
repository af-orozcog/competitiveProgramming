#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        int nums[n];
        int ans[n];
        for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
        int now[] = {0,n-1};
        int turn = 0;
        int index = 0;
        while(now[0] <= now[1]){
            ans[index] = nums[now[turn]];
            if(turn) --now[turn];
            else ++now[turn];
            ++turn;
            turn %= 2;
            ++index;
        }
        for(int i = 0; i < n;++i) printf("%d ",ans[i]);
        puts("");
    }
    return 0;
}
