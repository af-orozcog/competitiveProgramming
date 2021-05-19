#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,T;
        scanf(" %d %d",&n,&T);
        int ans[n];
        set<int> left;
        int imp = T/2;
        if(T&1) imp = -1;
        int last = 0;
        for(int i = 0; i < n;++i){
            int use; scanf(" %d",&use);
            if(use == imp){
                ans[i] = last++;
                if(last > 1) last -= 2;
                continue;
            }
            int needed = T-use;
            if(!left.count(needed)){
                ans[i] = 0;
                left.insert(use);
            }
            else ans[i] = 1;
        }
        for(int i = 0; i < n;++i)
            printf("%d ",ans[i]);
        puts("");
    }
    return 0;
}
