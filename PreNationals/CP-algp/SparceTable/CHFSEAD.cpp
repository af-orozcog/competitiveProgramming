#include<bits/stdc++.h>
using namespace std;

int K = 25;
int lg2[1000002];


int main(){
    lg2[1] = 0;
    for(int i = 2; i < 1000002;++i)
        lg2[i] = lg2[i/2]+1;
    int n,m;
    scanf(" %d",&n);
    int nums[n];
    for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
    int st[n-1][K+1];
    for(int i = 0; i < n-1;++i)
        st[i][0] = nums[i+1]-nums[i];
    for(int i = 1; i <= K;++i){
        for(int j = 0; (j+(1<<i)) < n;++j)
            st[j][i] = max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
    }
    scanf(" %d",&m);
    while(m--){
        int t,d;
        scanf(" %d %d",&t,&d);
        int from = upper_bound(nums,nums+n,t)-nums;
        --from;
        int lo = 2, hi = from+1, ans = 1;
        while(lo <= hi){
            int mid = (lo+hi)>>1;
            int f = from-mid+1;
            int imp = lg2[mid-1];
            int check = max(st[f][imp],st[from-(1<<imp)][imp]);
            if(check > d)
                hi = mid - 1;
            else
                ans = mid,lo = mid + 1;
        }
        printf("%d\n",from-ans+1+1);
    }
    return 0;
}
