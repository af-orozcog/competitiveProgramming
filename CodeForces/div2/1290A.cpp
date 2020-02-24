#include<bits/stdc++.h>

using namespace std;
int n,m,k,num[3600];

int solve(int i, int j, int many){
    int ans = 1000000001;
    for(int w = 0; w <= many;++w)
        ans = min(max(num[i+w],num[n-(many-w+j+1)]),ans);
    return ans;
}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        scanf(" %d %d %d",&n,&m,&k);
        for(int i = 0; i < n;++i) scanf(" %d",&num[i]);
        int ans = 0;
       // printf("%d %d %d\n",n,m,k);
        for(int i = 0; i <= min(k,m-1);++i)
            ans = max(solve(i,k-i,m-1-min(k,m-1)),ans);
        printf("%d\n",ans);
    }
    return 0;
}
