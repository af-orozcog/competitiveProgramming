#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        unordered_set<int> nums;
        for(int i = 0; i < n;++i){
            int va; scanf(" %d",&va);
            nums.insert(va);
        }
        printf("%d\n",(int)nums.size());
    }
    return 0;
}
