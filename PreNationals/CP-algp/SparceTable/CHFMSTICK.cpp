#include<bits/stdc++.h>
using namespace std;

int K = 20;
int lg2[100002];


int maximum(int l, int r, vector<vector<int>> &st){
    if(l > r) return 0;
    int imp = lg2[(r-l)+1];
    return max(st[l][imp],st[r-(1<<imp)+1][imp]);
}

int main(){
    lg2[1] = 0;
    for(int i = 2; i < 100002;++i)
        lg2[i] = lg2[i>>1] + 1;
    int n;
    scanf(" %d",&n);
    vector<vector<int>> st1(n,vector<int>(K+1));
    vector<vector<int>> st2(n,vector<int>(K+1));
    for(int i = 0; i < n;++i){
        scanf(" %d",&st1[i][0]);
        st2[i][0] = st1[i][0];
    }
    for(int i = 1; i <= K;++i){
        for(int j = 0; j + (1<<i) <= n;++j){
            st1[j][i] = min(st1[j][i-1],st1[j+(1<<(i-1))][i-1]);
            st2[j][i] = max(st2[j][i-1],st2[j+(1<<(i-1))][i-1]);
        }
    }
    int q;
    scanf(" %d",&q);
    while(q--){
        int l,r;
        scanf(" %d %d",&l,&r);
        int imp = lg2[(r-l)+1];
        int val1 = min(st1[l][imp],st1[r-(1<<imp)+1][imp]);
        int val2 = max(st2[l][imp],st2[r-(1<<imp)+1][imp]);
        val2 -= val1;
        int val3 = maximum(0,l-1,st2);
        int val4 = maximum(r+1,n-1,st2);
        double ans = (double)val1 + max((double)val2/(double)2.0,max((double)val3,(double)val4));
        printf("%.1lf\n",ans);
    }
    return 0;
}
