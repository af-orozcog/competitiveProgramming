#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        ll nums[n];
        for(int i = 0; i < n;++i)
            scanf(" %lld",&nums[i]);
        ll ma = nums[0];
        int ans = -1;
        for(int i = 1; i < n;++i){
            if(nums[i] >= ma) ma = nums[i];
            else{
                ll dif = ma - nums[i];
                int last = -1;
                ll co = dif;
                ll le = 1;
                while(co){
                    ++last;
                    co = co >> 1;
                }
                if(last > ans)
                    ans = last;
               // cout << last << endl;
            }
        }
        printf("%d\n",ans+1);
    }
    return 0;
}
