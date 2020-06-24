//hope to have a good performance to show Marie :)
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,k;
        scanf(" %d %d",&n,&k);
        int a[n],b[n];
        for(int i = 0; i < n;++i) scanf(" %d",&a[i]);
        for(int i = 0; i < n;++i) scanf(" %d",&b[i]);
        sort(a,a+n);
        reverse(a,a+n);
        sort(b,b+n);
        reverse(b,b+n);
        int ans = 0;
        for(int i = 0, j = 0, op = 0, who = 0; who < n;++who){
            if(op == k)
                ans += a[i++];
            else if(a[i] >= b[j])
                ans += a[i++];
            else if(a[i] < b[j])
                ans += b[j++],++op;
        }
        printf("%d\n",ans);
    }
    return 0;
}
