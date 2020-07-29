#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        ll ar[2],n,m;
        scanf(" %lld %lld %lld %lld",&ar[0],&ar[1],&n,&m);
        sort(ar,ar+2);
        if(ar[0]+ar[1] < n+m){puts("NO");continue;}
        if(ar[0] < m){puts("NO");continue;}
        if(ar[1]+ar[0]-m < n){puts("NO");continue;}
        puts("YES");
    }
    return 0;
}
