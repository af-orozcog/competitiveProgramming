#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,k;
        scanf(" %d %d",&n,&k);
        int ans = 0;
        if(k > n)
            ans = (k-n);
        else if(k == 0 && n&1)
            ans = 1;
        printf("%d\n",ans);
    }
    return 0;
}
