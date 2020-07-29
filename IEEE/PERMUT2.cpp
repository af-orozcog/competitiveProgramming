#include<bits/stdc++.h>
using namespace std;

int nums[100002];
int temp[100002];

int main(){
    int n;
    while(scanf(" %d",&n) && n){
        for(int i = 1; i <= n;++i){
            scanf(" %d",&nums[i]);
            temp[nums[i]] = i;
        }
        bool all = 1;
        for(int i = 1; i <= n && all;++i)
            if(nums[i] != temp[i]) all = 0;
        if(all) puts("ambiguous");
        else puts("not ambiguous");
    }
    return 0;
}
