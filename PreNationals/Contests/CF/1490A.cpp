#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int cal(int va1, int va2){
    int temp = 2;
    int ans = 1;
    while(va1 > va2*temp){
        temp<<=1;
        ++ans;
    }
    return ans-1;
}


int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        int nums[n];
        for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
        int ans = 0;
        for(int i = 0; i < n-1;++i)
            ans += cal(max(nums[i],nums[i+1]),min(nums[i],nums[i+1]));

        printf("%d\n",ans);
    }
    return 0;
}
