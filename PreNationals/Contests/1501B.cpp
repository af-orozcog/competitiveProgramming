#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        int ans[n];
        memset(ans,0,sizeof(ans));
        for(int i = 0; i < n;++i){
            int va;
            scanf(" %d",&va);
            ++ans[i];
            if(i-va > -1) --ans[i-va];
        }
        vector<int> lel;
        for(int i = n-1,sum = 0; i > -1;--i){
            sum+=ans[i];
            if(sum)
                lel.push_back(1);
            else
                lel.push_back(0);
        }
        reverse(lel.begin(),lel.end());
        for(auto va:lel)
            printf("%d ",va);
        puts("");
    }
    return 0;
}
