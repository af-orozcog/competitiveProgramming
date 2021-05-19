#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,m;
        scanf(" %d %d",&n,&m);
        map<int,int> seen;
        for(int i = 0; i < n;++i){
            int va; scanf(" %d",&va);
            ++seen[va%m];
        }
        int ans = 0;
        for(auto va:seen){
            int ma = max(va.second,seen[(m-va.first)%m]);
            int mi = min(va.second,seen[(m-va.first)%m]);
            ++ans;
            if(ma > mi)
                ans += ma-mi-1;
            if((m-va.first)%m != va.first)
                seen.erase((m-va.first)%m);
        }

        printf("%d\n",ans);
    }
    return 0;
}
