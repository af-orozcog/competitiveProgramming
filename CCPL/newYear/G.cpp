#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int W,N;
        scanf(" %d %d",&W,&N);
        int acum = 0;
        int ans = 0;
        int last = 0;
        for(int i = 0; i < N;++i){
            int x,w;
            scanf(" %d %d",&x,&w);
            if(acum + w > W)
                ans += (x-last)+(x<<1),last = x,acum = w;
            else if(acum + w == W)
                 ans += (x-last)+(i != N-1?(x<<1):x),last = x,acum = 0;
            else
                acum += w,ans += (x-last),last = x;
        }
        if(acum != 0) ans += last;
        printf("%d\n",ans);
    }
    return 0;
}
