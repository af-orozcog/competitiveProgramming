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
        vector<int> seen1(101,0),seen2(101,0);
        for(int i = 0; i < n;++i){
            int va;scanf(" %d",&va);
            ++seen1[va];
        }
        for(int i = 0; i < m;++i){
            int va; scanf(" %d",&va);
            ++seen2[va];
        }
        int ans = 0;
        for(int i = 0; i < 101;++i){
            if(seen1[i] && seen2[i]) ++ans;
        }
        printf("%d\n",ans);
    }
    return 0;
}
