#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        ll k,n;
        scanf(" %lld %lld",&k,&n);
        if(n >= 2000ll){puts("-1");continue;}
        int tama = 1;
        for(ll i = 2 ; i*i <= (k<<1) && i < 2000ll;++i){
            if((k<<1) % i == 0){
                tama = max(tama,(int)i);
                ll see = (k<<1)/i;
                if(see < 2000ll)
                    tama = max((int)see,tama);
            }
        }
        int ans[tama];
        memset(ans,0,sizeof(ans));
        ll tar2 = (k<<1)/tama;
        ans[0] = k;
        ans[1] = -(k+1ll);
        int add = 0;
        ll imp1 = tar2/2;
        tar2 -= imp1;
        ans[tama-3] = (int)imp1+1;
        ans[tama-4] -= 1;
        ans[tama-2] -= 1;
        ans[tama-1] = (int)tar2+2;
        printf("%d\n",tama);
        for(int i = 0; i < tama;++i)
            printf("%d ",ans[i]);
        puts("");
    }
    return 0;
}
