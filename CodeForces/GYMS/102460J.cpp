#include<bits/stdc++.h>
#define ll long long
using namespace std;

bitset<501> nums[16];

int main(){
    int t;
    scanf(" %d ",&t);
    while(t--){
        int n,m;
        scanf(" %d %d",&n,&m);
        for(int i = 0; i < m;++i){
            nums[i].reset();
            for(int j = 0; j < n;++j){
                char ve; scanf(" %c",&ve);
                if(ve == '1')
                    nums[i][j] = 1;
                else
                    nums[i][j] = 0;
            }
        }
        int ans = m;
        bool found = 0;
        for(int i = 1; i < (1<<m);++i){
            bitset<501> temp;
            int j = 0;
            int used = 0;
            int co = i;
            while(co){
                if(co&1)
                    temp = temp | nums[j], ++used;
                ++j;
                co>>=1;
            }
            if(temp.count() == n)
                ans = min(ans,used),found = 1;
        }
        if(found)
            printf("%d\n",ans);
        else
            puts("-1");
    }
    return 0;
}
