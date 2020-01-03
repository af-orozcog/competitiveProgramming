#include<bits/stdc++.h>
#define ll long long
using namespace std;

int look(int f, ll tim, ll sums[], int n){
    if(tim < 0) return -1000000000;
    int lo = f+1,hi = n-1,ans = 0;
    while(lo <= hi){
        int mid = (lo+hi)>>1;
        if(sums[mid]-sums[f] - tim >= 0){
            ans = mid -f;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    return ans;
}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        ll n,s;
        cin >> n >> s;
        ll nums[n],sums[n];
        int a = 0;
        for(int i = 0; i < n;++i){
            cin >> nums[i];
            if(i == 0) sums[i] = nums[i];
            else sums[i] = sums[i-1]+nums[i];
            if(sums[i] <= s) a = i+1;
        }
        if(sums[n-1] <= s){
            puts("0");
            continue;
        }
        int ans = a;
        int seg = 0;
        for(int i = 0; i < n;++i){
            if((i,s-(i == 0? 0:sums[i-1]),sums,n) + i > ans){
                ans = (i,(i == 0? 0:sums[i-1]),sums,n) + i;
                seg = i+1;
            }
        }
        printf("%d\n",seg);
    }
    return 0;
}
