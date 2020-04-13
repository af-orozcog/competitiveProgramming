#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
int va = (24*60)+1;

int main(){
    int t,cas = 1;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        pair<int,pi> nums[n];
        for(int i = 0; i < n;++i){
            scanf(" %d %d",&nums[i].first,&nums[i].second);
            nums[i].second.second = i;
        }
        sort(nums,nums+n);
        bool C = 1;int en1 = 1000000;
        bool J = 1;int en2 = 1000000;
        string ans = "";
        bool pos = 1;
        for(int i = 0,j = 0; i < va && pos;++i){
            if(i == en1) C = 1, en1 = 1000000;
            if(i == en2) J = 1, en2 = 1000000;
            if(j < n && i == nums[j].first){
                if(!C && !J) pos = 0;
                if(C) ans += 'C',en1 = nums[j].second.first,C = 0;
                else if(J) ans += 'J', en2 = nums[j].second.first, J = 0;
                ++j;
                --i;
            }
        }
        printf("Case #%d: ",cas++);
        if(!pos){puts("IMPOSSIBLE");continue;}
        vector<char> an(n);
        for(int i = 0; i < n;++i) an[nums[i].second.second] = ans[i];
        for(auto va: an) printf("%c",va);
        puts("");
    }
}
