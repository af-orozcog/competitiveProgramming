#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        int nums[n];
        for(int i = 0; i < n;++i)
            scanf(" %d",&nums[i]);
        int con = 0;
        for(int i = 0; i < n-1 && nums[i] == 1;++i)
            ++con;
        if((con&1) == 0)puts("First");
        else puts("Second");
    }
    return 0;
}
