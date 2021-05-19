#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        map<int,int> mp;
        for(int i = 0; i < n;++i){
            int va;
            scanf(" %d",&va);
            ++mp[va];
        }
        priority_queue<int> q;
        for(auto &va:mp)
            q.push(va.second);
        int ans = n;
        while(q.size() > 1){
            int see1 = q.top();
            q.pop();
            int see2 = q.top();
            q.pop();
            ans -= 2;
            if(see1 > 1)
                q.push(see1-1);
            if(see2 > 1)
                q.push(see2-1);
        }
        printf("%d\n",ans);
    }
    return 0;
}
