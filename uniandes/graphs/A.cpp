#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf(" %d",&n);
    int nums[n];
    for(int i = 0; i < n;++i){scanf(" %d",&nums[i]);--nums[i];}
    int ans = 0;
    for(int i = 0; i < n && !ans;++i){
        if(nums[i] != i && nums[nums[i]] != i && nums[nums[i]] != nums[i] && nums[nums[nums[i]]] == i)
            ans = 1;
    }
    cout << (ans? "YES": "NO") << "\n";
    return 0;
}
