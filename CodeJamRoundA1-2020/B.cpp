#include<bits/stdc++.h>
#define ll long long
using namespace std;

void ansPrint(int n){
    for(int i = 0,j = 1; i <= n;++i,++j){
        if(i&1){
            for(int k = j; k > 0;--k)
                printf("%d %d\n",i+1,k);
        }
        else{
            for(int k = 1; k <= j;++k)
                printf("%d %d\n",i+1,k);
        }
    }
}

int main(){
    int t;
    scanf(" %d",&t);
    int cas = 1;
    while(t--){
        ll n;
        scanf(" %lld",&n);
        int highest = -1;
        ll co = n;
        while(co){
            ++highest;
            co >>= 1;
        }
        printf("Case #%d:\n",cas++);
        if(n == 1ll){
            puts("1 1");
            continue;
        }
        else{
            ansPrint(highest-1);
            ll left = n - ((1<<(highest))-1ll);
            int co = highest;
            while(highest > 1 && left >= (ll)highest){
                left -= highest;
                printf("%d %d\n",highest+1,(co&1? highest:2));
                ++highest;
            }
            while(left){
                --left;
                printf("%d %d\n",highest+1,(co&1? highest+1: 1));
                ++highest;
            }
        }
    }
    return 0;
}
