#include<bits/stdc++.h>
using namespace std;

int re[11];

int main(){
    int t;
    scanf(" %d",&t);
    int ca = 1;
    while(t--){
        int n;
        scanf(" %d",&n);
        for(int i = 0; i < n;++i) scanf(" %d",&re[i]);
        printf("Case %d: %d\n",ca++,re[n>>1]);
    }
    return 0;
}
