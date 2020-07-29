#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        int nums[n<<1];
        set<int> ava;
        for(int i = 0; i < (n<<1);++i){
            scanf(" %d",&nums[i]);
            ava.insert(nums[i]);
        }
        int turn[2] = {0,0};
        int last = 1000000000;
        bool posi = 1;
        for(int i = 0; i < (n<<1) && posi;++i){
            if(last > nums[i]){
                ++turn[0];
                if(turn > n) posi = 0;
            }
        }
        if(posi) puts("YES");
        else puts("NO");
    }
    return 0;
}
