#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,m;
        scanf(" %d %d",&n,&m);
        vector<int> co(1002,0);
        int ans = -1;
        for(int i = 0; i < n;++i){
            int va; scanf(" %d",&va);
            ++co[va];
        }
        for(int i = 0; i < m;++i){
            int va; scanf(" %d",&va);
            if(co[va]) ans = va;
        }
        if(ans == -1){puts("NO");continue;}
        puts("YES");
        printf("1 %d\n",ans);
    }
    return 0;
}
