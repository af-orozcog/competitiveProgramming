#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,t,a,b;
        scanf(" %d %d %d %d",&n,&t,&a,&b);
        priority_queue<pair<int,int>> q;
        vector<pair<int,int>> nums(n);
        for(int i = 0; i < n;++i){
            int va;scanf(" %d",&va);
            nums[i].second = (va?-b:-a);
        }
        for(int i = 0; i < n;++i){
            int va;scanf(" %d",&va);
            nums[i].first = -va;
        }
        for(int i = 0;i < n;++i) q.push(nums[i]);
        int ans = 0;
        int T = 0;
        vector<int> last;
        while(q.size()){
            int f1 = -q.top().first,f2 = -q.top().second;
            q.pop();
            if(f2+T <= t){
                T += f2;
                last.push_back(T);
                ++ans;
            }
            else{
                int index = lower_bound(last.begin(),last.end(),f1)-last.begin();
                ans -= ((int)last.size()-index);
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
