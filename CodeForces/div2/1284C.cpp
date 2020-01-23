#include<bits/stdc++.h>
#define ll long long
using namespace std;


int fact[250003];

int main(){
    int n,m;
    scanf(" %d %d",&n,&m);
    fact[0] = 1;
    for(int i = 1;i < n+2;++i)
        fact[i] = ((ll)fact[i-1]*(ll)i)%(ll)m;
    int ans = 0;
    for(int i = 1; i <= n;++i)
        ans = ((ll)ans + (ll)(n-i+1)*(((ll)fact[i]*(ll)fact[n-i+1])%(ll)m))%(ll)m;
    printf("%d\n",ans);
    return 0;
}
