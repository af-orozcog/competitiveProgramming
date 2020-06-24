#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf(" %d",&n);
    int ans[n+1];
    memset(ans,0,sizeof(ans));
    for(int i = 0; i < n-1;++i){
        int va; scanf(" %d",&va);
        ++ans[va];
    }
    for(int i = 1; i <= n;++i) printf("%d\n",ans[i]);
    return 0;
}
