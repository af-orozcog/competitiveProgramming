#include<bits/stdc++.h>
using namespace std;

int K = 16;
int lg2[1000000];

int main(){
    lg2[1] = 0;
    for(int i = 2; i < 1000000;++i)
        lg2[i] = lg2[i>>1] + 1;

    int n,m;
    while(scanf(" %d %d",&n,&m) == 2){
        int st[n][K+1];
        for(int i = 0; i < n;++i)
            scanf(" %d",&st[i][0]);
        for(int i = 1; i <= K;++i){
            for(int j = 0; (j+(1<<i))<= n;++j)
                st[j][i] = max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
        }
        int ans = 0;
        while(m--){
            int l,r;
            scanf(" %d %d",&l,&r);
            if(l == r) ++ans;
            else if(l + 1 == r) ++ans;
            else{
                r -= 2;
                int imp = lg2[(r-l)+1];
                ans += (max(st[l][imp],st[r-(1<<imp)+1][imp]) <= st[l-1][0]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
