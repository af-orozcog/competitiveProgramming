#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    while(scanf(" %d %d",&n,&k) == 2){
        priority_queue<int> q;
        for(int i = 0; i < ((n*k)<<1);++i){
            int va; scanf(" %d",&va);
            q.push(-va);
        }
        int ans = 0;
        for(int i = 0; i < n;++i){
            int f1 = -q.top();q.pop();
            int f2 = -q.top();q.pop();
            ans = max(ans,f2-f1);
        }
        printf("%d\n",ans);
    }
    return 0;
}
