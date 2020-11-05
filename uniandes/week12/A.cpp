#include<bits/stdc++.h>
#define ll long long
using namespace std;

int imp = 1;

int main(){
    int t;
    scanf(" %d",&t);
    int cas = 1;
    while(t--){
        int n,k;
        scanf(" %d %d",&n,&k);
        int see = (imp<<n);
        ++k;
        printf("Case #%d: ",cas++);
        if(k % see == 0) puts("ON");
        else puts("OFF");
    }
    return 0;
}
