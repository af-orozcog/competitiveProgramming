#include<bits/stdc++.h>
using namespace std;

int K = 25;
int lg2[100001];

int main(){
    int n;
    scanf(" %d",&n);
    lg2[1] = 0;
    for(int i = 2; i < 100001;++i)
        lg2[i] = lg2[i>>1]+1;
    int st[n][K+1];
    for(int i = 0; i < n;++i)
        scanf(" %d",&st[i][0]);
    for(int i = 1; i <= K;++i){
        for(int j = 0;(j+(1<<i)) <= n;++j){
            st[j][i] = min(st[j][i-1],st[j+(1<<(i-1))][i-1]);
        }
    }
    int q;
    scanf(" %d",&q);
    while(q--){
        int l,r;
        scanf(" %d %d",&l,&r);
        int imp = lg2[(r-l+1)];
        printf("%d\n",min(st[l][imp],st[r-(1<<imp)+1][imp]));
    }
    return 0;
}
