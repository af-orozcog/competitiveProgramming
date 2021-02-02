#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        vector<bool> use;
        while(n){
            if(n&1) use.push_back(1);
            else use.push_back(0);
            n >>=1;
        }
        reverse(use.begin(),use.end());
        int ans = 1;
        for(int j = use.size()-1; j > -1;++ans,--j)
            if(use[j])break;
        printf("%d\n",ans);
    }
}
