#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

int main(){
    int k,n;
    scanf(" %d %d",&k,&n);
    int nums[n];
    for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
    int acum1[n];
    acum1[0] = 0;
    for(int i = 1; i < n;++i)
        acum1[i] = acum1[i-1] + (nums[i]-nums[i-1]);
    int sum = nums[0] + k - nums[n-1];
    //cout << sum << "\n";
    int ans = acum1[n-1];
    ans = min(ans,sum + acum1[n-1]-acum1[1]);
    ans = min(ans,sum+acum1[n-2]);
    for(int i = 1; i < n-1;++i){
        int va1 = acum1[i] + sum + (acum1[n-1]-acum1[i+1]);
        int va2 = (acum1[n-1]-acum1[i]) + sum + acum1[i-1];
        va1 = min(va1,va2);
        ans = min(ans,va1);
    }
    printf("%d\n",ans);
    return 0;
}
