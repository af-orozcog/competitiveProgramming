#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,k1,k2;
        scanf(" %d %d %d",&n,&k1,&k2);
        int ma1 =0,ma2 = 0;
        for(int i = 0; i < k1;++i){
            int va; scanf(" %d",&va);
            ma1 = max(ma1,va);
        }
        for(int i = 0; i < k2;++i){
            int va;scanf(" %d",&va);
            ma2 = max(ma2,va);
        }
        if(ma1 > ma2) puts("YES");
        else puts("NO");
    }
    return 0;
}
