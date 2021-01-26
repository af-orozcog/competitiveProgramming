#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

int main(){
    int n,x;
    scanf(" %d %d",&n,&x);
    x*= 100;
    int now = 0;
    int i = 0;
    int ans = -1;
    for(; i < n;++i){
        int v,p;
        scanf(" %d %d",&v,&p);
        now += v*p;
        if(now > x && ans == -1) ans = i+1;
    }
    printf("%d\n",ans);
    return 0;
}
