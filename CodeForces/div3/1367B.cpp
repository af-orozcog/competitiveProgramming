#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        int nums[n];
        for(int i = 0; i < n;++i)scanf(" %d",&nums[i]);
        int bad[2];
        bad[0] = bad[1] = 0;
        for(int i = 0; i < n;++i){
            if(i%2 != nums[i]%2)
                ++bad[nums[i]%2];
        }
        if(bad[0] != bad[1]) puts("-1");
        else printf("%d\n",bad[0]);
    }
    return 0;
}
