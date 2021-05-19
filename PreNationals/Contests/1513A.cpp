#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,k;
        scanf(" %d %d",&n,&k);
        int ma = n/2 + (n&1?0:-1);
        if(k > ma) {puts("-1");continue;}
        int ans[n];
        memset(ans,-1,sizeof(ans));
        for(int i = 1, j = n, lel = 0; i < n && lel < k;i+=2,j--,++lel)
            ans[i] = j;
        for(int i = 0,j = 1; i < n;++i)
            if(ans[i] == -1) ans[i] = j++;
        for(int i = 0; i < n;++i) printf("%d ",ans[i]);
        puts("");
    }
    return 0;
}
