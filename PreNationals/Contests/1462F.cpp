#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        pi nums[n];
        for(int i = 0; i < n;++i)
            scanf(" %d %d",&nums[i].first,&nums[i].second);
        sort(nums,nums+n);
        int ans = n;
        priority_queue<int> q;
        for(int i = 0; i < n;++i){
            while(q.size() && -q.top() < nums[i].first)
                q.pop();
            pi look1 = {nums[i].first,0};
            pi look2 = {nums[i].second+1,0};
            int from = lower_bound(nums+i+1,nums+n,look1)-nums;
            int to = lower_bound(nums+i+1,nums+n,look2)-nums;
            int add = to-from + (int)q.size()+1;
            ans = min(ans,n-add);
            q.push(-nums[i].second);
        }
        printf("%d\n",ans);
    }
    return 0;
}
