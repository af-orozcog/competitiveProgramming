#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        char a[n+1],b[n+1];
        scanf(" %s %s",a,b);
        int sum[n];
        memset(sum,0,sizeof(sum));

        for(int i = 0; i < n;++i){
            if(a[i] == '1') ++sum[i];
            else --sum[i];
            if(i) sum[i] += sum[i-1];
        }
        bool ans = 1;
        if(n&1)
            ans = (a[n-1] == b[n-1]);
        for(int i = n-1-(n&1), val = 0; i > 0 && ans;i-=2){
            int mismatches = ((a[i]-'0'+val)%2 != b[i]-'0') + ((a[i-1]-'0'+val)%2 != b[i-1]-'0');
            if(mismatches == 1 || (mismatches == 2 && sum[i] != 0)) ans = 0;
            else if(mismatches == 2)
                val = (val+1)%2;
        }

        if(ans) puts("YES");
        else puts("NO");
    }
    return 0;
}
