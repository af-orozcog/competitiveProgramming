#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

int different(pair<int,int> a, pair<int,int> b){
    pair<int,int> imp = {min(a.first,b.first),max(a.second,b.second)};
    return imp.second-imp.first+1;
}

int lg2[1000000];
int K = 25;

int main(){
    lg2[1] = 0;
    for(int i = 2; i < 1000000;++i)
        lg2[i] = 1 + lg2[i>>1];
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,q;
        scanf(" %d %d",&n,&q);
        char see[n+1];
        scanf(" %s",see);
        int stMi[K+1][n];
        int stMa[K+1][n];
        int act = 0;
        for(int i = 0; i < n;++i){
            if(see[i] == '+') ++act;
            else --act;
            stMi[0][i] = stMa[0][i] = act;
        }
        for(int i = 1; i <= K;++i){
            for(int j = 0; j+(1<<i) <= n;++j){
                stMi[i][j] = min(stMi[i-1][j],stMi[i-1][j+(1<<(i-1))]);
                stMa[i][j] = max(stMa[i-1][j],stMa[i-1][j+(1<<(i-1))]);
            }
        }
        while(q--){
            int l,r;
            scanf(" %d %d",&l,&r);
            --l,--r;
            if(l == 0 && r != n-1){
                int imp = lg2[n-r];
                int top = max(stMa[imp][r],stMa[imp][n-(1<<imp)])-stMa[0][r];
                int but = min(stMi[imp][r],stMi[imp][n-(1<<imp)])-stMa[0][r];
                printf("%d\n",top-but+1);
            }
            else if(r == n-1 && l != 0){
                int imp = lg2[l];
                int top = max(stMa[imp][0],max(stMa[imp][l-(1<<imp)],0));
                int but = min(stMi[imp][0],min(stMi[imp][l-(1<<imp)],0));
                printf("%d\n",top-but+1);
            }
            else if(l == 0 && r == n-1)
                puts("1");
            else{
                int imp1 = lg2[l];
                int imp2 = lg2[n-r];
                pair<int,int> a = {min(stMi[imp1][0],min(stMi[imp1][l-(1<<imp1)],0)),max(stMa[imp1][0],max(stMa[imp1][l-(1<<imp1)],0))};
                pair<int,int> b = {min(stMi[imp2][r],stMi[imp2][n-(1<<imp2)])-stMi[0][r]+stMi[0][l-1],max(stMa[imp2][r],stMa[imp2][n-(1<<imp2)])-stMi[0][r]+stMi[0][l-1]};
                printf("%d\n",different(a,b));
            }
        }
    }
    return 0;
}
