#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){
    int n,k;
    scanf(" %d %d",&n,&k);
    char ans[n+1];
    ans[n] = '\0';
    char let = 'a';
    char ot = 'a';
    char upTo = 'a' + k;
    for(int i = 0; i < n;){
        ans[i] = let;
        if(i+1 < n) ans[i+1] = ot;
        if(ot == let) ++ot,++i;
        else ++ot,i+=2;
        if(ot == upTo){
            ++let;
            ot = let;
            if(let == upTo)
                let = ot = 'a';
        }
    }
    printf("%s\n",ans);
    return 0;
}
