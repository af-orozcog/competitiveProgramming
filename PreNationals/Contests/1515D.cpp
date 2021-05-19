#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,l,r;
        scanf(" %d %d %d",&n,&l,&r);
        map<int,int> mp1;
        map<int,int> mp2;
        for(int i = 0; i < l;++i){
            int va; scanf(" %d",&va);
            ++mp1[va];
        }
        for(int i = 0; i < r;++i){
            int va; scanf(" %d",&va);
            ++mp2[va];
        }
        if(l < r){
            swap(l,r);
            swap(mp1,mp2);
        }
        int ans = 0;
        int left = (n/2)-r;
        for(auto &va:mp1){
            int check = (va.second)/2;
            if(!mp2.count(va.first)){
                int imp = min(check,left);
                ans += imp;
                left -= imp;
                va.second -= imp*2;
            }
        }
        for(auto &va:mp1){
            va.second -= min(va.second,mp2[va.first]);
            int imp = min(left,va.second/2);
            ans += imp;
            left -= imp;
            va.second -= imp*2;
            ans += va.second;
        }
        printf("%d\n",ans);
    }
    return 0;
}
