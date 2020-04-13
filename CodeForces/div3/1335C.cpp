#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        map<int,int> fr;
        for(int i = 0; i < n;++i){
            int va;
            scanf(" %d",&va);
            ++fr[va];
        }
        int uni = fr.size();
        int ans = 0;
        for(auto va:fr){
            if(uni > va.second)
                ans = max(ans,va.second);
            else if(uni == va.second)
                ans = max(ans,uni-1);
            else if(uni < va.second)
                ans = max(ans,uni);
        }
        printf("%d\n",ans);
    }
    return 0;
}
