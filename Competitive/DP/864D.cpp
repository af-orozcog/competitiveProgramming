#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf(" %d",&n);
    set<int> vals;
    for(int i = 1; i <= n;++i) vals.insert(i);
    int nums[n];
    map<int,int> freq;
    for(int i = 0; i < n;++i){
        scanf(" %d",&nums[i]);
        ++freq[nums[i]];
        vals.erase(nums[i]);
    }
    int changes = 0;
    set<int> toChange;
    for(int i = 0; i < n;++i){
        if((freq[nums[i]]>=2 && *(vals.begin()) < nums[i]) || toChange.count(nums[i])){
            ++changes;
            --freq[nums[i]];
            nums[i] = *(vals.begin());
            vals.erase(vals.begin());
            toChange.erase(nums[i]);
        }
        else if(freq[nums[i]] >= 2){
            --freq[nums[i]];
            toChange.insert(nums[i]);
        }
    }
    printf("%d\n",changes);
    for(int i = 0; i < n;++i) printf("%d ",nums[i]);
    puts("");return 0;
}
