#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        int nums[n+1];
        vector<pair<int,pi>> ans;
        for(int i = 1; i <= n;++i) scanf(" %d",&nums[i]);
        int sum = 0;
        for(int i = 1; i <= n;++i) sum += nums[i];
        if(sum % n != 0){
            puts("-1");
            continue;
        }
        sum /= n;
        for(int i = 2; i <= n;++i){
            if(nums[i] % i != 0){
                nums[1] -= i - (nums[i]%i);
                nums[i] += i - (nums[i]%i);
                ans.push_back({1,{i,i-(nums[i]%i)}});
            }
            int see = nums[i]/i;
            ans.push_back({i,{1,see}});
            nums[1] += i*see;
            nums[i] -= i*see;
        }
        for(int i = 2; i <= n;++i){
            if(nums[i] == sum) continue;
            int needed = sum - nums[i];
            ans.push_back({1,{i,needed}});
            nums[i] -= needed;
        }
        printf("%d\n",(int)ans.size());
        for(auto &va:ans) printf("%d %d %d\n",va.first,va.second.first,va.second.second);
    }
    return 0;
}
