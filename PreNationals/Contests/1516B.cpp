#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        int nums[n];
        for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
        int left[n];
        int right[n];
        left[0] = nums[0];
        right[n-1] = nums[n-1];
        for(int i = 1; i < n;++i) left[i] = nums[i] ^ left[i-1];
        for(int i = n-2; i > -1;--i) right[i] = nums[i] ^ right[i+1];
        bool ans = 0;
        for(int i = 0; i < n && !ans;++i){
            for(int j = i+1; j < n && !ans;++j){
                if(left[i] == right[j]){
                    if(i+1 == j) ans = 1;
                    else if((left[j-1]^left[i]) == left[i]) ans = 1;
                }
            }
        }


        if(ans)puts("YES");
        else puts("NO");
    }
    return 0;
}
