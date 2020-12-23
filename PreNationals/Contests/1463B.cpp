#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

int main(){
    int t;
    scanf(" %d",&t);
    vector<int> vals;
    for(int i = 0; i <= 30;++i)
        vals.push_back(1<<i);
    while(t--){
        int n;
        scanf(" %d",&n);
        int nums[n];
        for(int i = 0; i < n;++i){
            scanf(" %d",&nums[i]);
        }
        for(int i = 0; i < n;++i){
            int index = lower_bound(vals.begin(),vals.end(),nums[i])-vals.begin();
            if(index == vals.size() || vals[index] > nums[i])--index;
            printf("%d ",vals[index]);
        }
        puts("");
    }
    return 0;
}
