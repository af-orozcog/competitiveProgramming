#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

int main(){
    int q;
    scanf(" %d",&q);
    while(q--){
        int n;
        scanf(" %d",&n);
        int nums[n];
        for(int i = 0; i < n;++i) {
            scanf(" %d",&nums[i]);
            --nums[i];
        }
        bool posi = 1;
        for(int i = 1; i < n && posi;++i)
            if((nums[i-1]+1)%n != nums[i])posi = 0;

        if(posi){puts("YES");continue;}
        posi = 1;
        for(int i = n-2; i > -1;--i)
            if((nums[i+1]+1)%n != nums[i])posi = 0;
        if(posi) puts("YES");
        else puts("NO");
    }
    return 0;
}
