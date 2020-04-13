#include<bits/stdc++.h>
#define ll long long
#define MAX 1005

const ll mod = 7901;

ll fact[MAX], cnt[MAX];

void prec(){
    fact[0]=1;
    for(int i = 1; i<MAX; ++i){
        fact[i]=(i*fact[i-1])%mod;
    }
}

int main(){
    int t, n,x;
    ll rta;
    cin>>t;
    while(t--){
        memset(cnt, 0, sizeof(cnt));
        cin>>n;
        for(int i = 0; i<n; ++i){
            cin>>x;
            ++cnt[x];
        }
        rta =1;
        for(int i = 1; i<MAX; ++i){
            rta = (rta*fact[cnt[i]])%mod;
        }
        cout<<rta<<"\n";
    }
    return 0;
}
