#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        int nums[n<<1];
        int be = 0,sta = 0;
        for(int i = 0; i < (n<<1);++i){
            scanf(" %d",&nums[i]);
            if(nums[i] == 1) ++sta;
            else ++be;
        }
        if(be == sta){puts("0");continue;}
        map<int,int> fr;
        fr[0] = 0;
        int te = 0,ta = 0;
        for(int i = n-1,k = 1; i > -1;--i,++k){
            if(nums[i] == 1) ++ta;
            else ++te;
            if(!fr.count(te-ta)) fr[te-ta] = k;
        }
        //cout << sta - be << endl;
        int ans = (n<<1);
        if(fr.count(be-sta))ans = min(fr[be-sta],ans);
        for(int i = n,k = 1; i < (n<<1);++i,++k){
            if(nums[i] == 1) --sta;
            else --be;
            if(fr.count(be-sta)) ans = min(ans,fr[be-sta]+k);
        }
        printf("%d\n",ans);
    }
    return 0;
}
