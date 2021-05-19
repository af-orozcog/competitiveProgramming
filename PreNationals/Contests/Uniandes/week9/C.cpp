#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,q;
        scanf(" %d %d",&n,&q);
        char see[n+1];
        scanf(" %s",see);
        vector<int> first(2,INT_MAX),last(2,INT_MIN);
        for(int i = 0; i < n;++i){
            if(see[i] == '0') first[0] = min(first[0],i),last[0] = max(last[0],i);
            else first[1] = min(first[1],i), last[1] = max(i,last[1]);
        }
        while(q--){
            int l,r;
            scanf(" %d %d",&l,&r);
            --l,--r;
            if(l > first[see[l]-'0'] || r < last[see[r]-'0']) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}
