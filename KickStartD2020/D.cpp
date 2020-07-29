#include<bits/stdc++.h>
using namespace std;

int nums[100005];

int main(){
    int t;
    scanf(" %d",&t);
    int cas = 1;
    while(t--){
        int n,q;
        scanf(" %d %d",&n,&q);
        for(int i = 0; i < n-1;++i)
            scanf(" %d",&nums[i]);
        printf("Case #%d: ",cas++);
        while(q--){
            int where,up;
            scanf(" %d %d",&where,&up);
            priority_queue<pair<int,int>> q;
            --where;
            if(where != n-1) q.push({-nums[where],where+1});
            if(where != 0) q.push({-nums[where-1],where-1});
            int ans = where;
            --up;
            while(up--){
                pair<int,int> see = q.top();
                q.pop();
                ans = see.second;
                if(ans < where && ans != 0)
                    q.push({-nums[ans-1],ans-1});
                if(ans > where && ans != n-1)
                    q.push({-nums[ans],ans+1});
            }
            printf("%d ",ans+1);
        }
        puts("");
    }
    return 0;
}
