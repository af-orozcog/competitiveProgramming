#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,m;
        scanf(" %d %d",&n,&m);
        vector<vector<int>> lel(m);
        vector<int> ans(m);
        vector<int> seen(n+1,0);
        bool posi = 1;
        for(int i = 0; i < m;++i){
            int k;
            scanf(" %d",&k);
            while(k--){
                int see;
                scanf(" %d",&see);
                lel[i].push_back(see);
            }
            if(lel[i].size() == 1){
                ++seen[lel[i].back()];
                ans[i] = lel[i].back();
                posi = posi & (seen[lel[i].back()] <= (m+1)/2);
            }
        }

        for(int i = 0; i < m && posi;++i){
            if(lel[i].size() == 1)continue;
            int mi = INT_MAX;
            int who;
            for(auto va:lel[i]){
                if(mi > seen[va]){
                    mi = seen[va];
                    who = va;
                }
            }
            ++seen[who];
            if(seen[who] > (m+1)/2) posi = 0;
            ans[i] = who;
        }

        if(!posi){
            puts("NO");
            continue;
        }
        puts("YES");
        for(auto va:ans)
            printf("%d ",va);
        puts("");
    }
    return 0;
}
