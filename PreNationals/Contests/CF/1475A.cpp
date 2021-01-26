#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        ll n;
        scanf(" %lld",&n);
        while(n%2 == 0)
            n >>=1;
        if(n != 1) puts("YES");
        else puts("NO");
    }
    return 0;
}
