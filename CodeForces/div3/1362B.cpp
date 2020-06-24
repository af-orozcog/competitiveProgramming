#include<bits/stdc++.h>
using namespace std;

bool checkk(int va, set<int> &check){
    set<int> see;
    for(int ve:check){
        int add = va ^ ve;
        if(check.count(add)) see.insert(add);
        else break;
    }
    return see.size() == check.size();
}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        int nums[n];
        set<int> check;
        for(int i = 0; i < n;++i){
            scanf(" %d",&nums[i]);
            check.insert(nums[i]);
        }
        int ans = 1000000000;
        for(int i = 1; i < n;++i){
            int see =  nums[i]^nums[0];
            if(checkk(see,check))
                ans = min(see,ans);
        }
        printf("%d\n",(ans == 1000000000? -1:ans));
    }
    return 0;
}
