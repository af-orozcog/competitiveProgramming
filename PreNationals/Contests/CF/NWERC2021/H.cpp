#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){
    int n;
    scanf(" %d",&n);
    int nums[n];
    for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
    sort(nums,nums+n);
    vector<int> ans;
    int i = n/2;
    if(n % 2 == 0) --i;
    int j = i +1;
    vector<int> one,two;
    while(i > -1){
        one.push_back(nums[i]);
        --i;
    }
    while(j < n){
        two.push_back(nums[j]);
        ++j;
    }
    for(int i = 0, j = 0; i < one.size() || j < two.size();++i,++j){
        if(i < one.size())
            ans.push_back(one[i]);
        if(j < two.size())
            ans.push_back(two[j]);
    }
    for(auto va: ans) printf("%d ",va);
    puts("");
    return 0;
}
