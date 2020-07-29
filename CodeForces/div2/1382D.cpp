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
        int posi = 1;
        for(int i = 0; i < (n<<1) && posi;++i){
            if(last > nums[i]){
                auto next = ava.lower_bound(nums[i]);
                ++next;
                ++turn[0];
                if(turn[0] > n) posi = 0;
                if(next == ava.end() && turn[1] != n)posi = 0;
            }
            else{
                swap(turn[0],turn[1]);
                ++turn[0];
                if(turn[0] > n) posi = 0;
            }
            ava.erase(nums[i]);
            last = nums[i];
        }
        if(posi) puts("YES");
        else puts("NO");
    }
    return 0;
}
