#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;

int n,a,b,c;

vector<int> ans;

bool possible(vector<int> &see){
    int ma = 0;
    vector<int> both(see.size(),0);
    int co1 = 0,co2 = 0,co3 = 0;
    for(int i = 0; i < see.size();++i){
        if(see[i] >= ma)
            ++co1,ma = see[i],++both[i];
    }
    ma = 0;
    for(int i = (int)see.size()-1; i > -1;--i){
        if(see[i] >= ma)
            ++co2,ma = see[i],++both[i];
        if(both[i] > 1)
            ++co3;
    }
    return co1 == a && co2 == b && co3 == c;
}

void check(vector<int> &see, int k, int left, int ma){
    if(left < 0) return;
    if(k == n){
        if(possible(see))
            ans = see;
        return;
    }
    if(ans.size()) return;
    for(int i = 1; i <= max(n,50) && !ans.size();++i){
        see[k] = i;
        int les = (i >= ma);
        check(see,k+1,left-les,max(ma,see[k]));
    }
}

int main(){
    int t;
    scanf(" %d",&t);
    int cas = 1;
    while(t--){
        ans.clear();
        scanf(" %d %d %d %d",&n,&a,&b,&c);
        vector<int> see(n);
        check(see,0,a,0);
        printf("Case #%d: ",cas++);
        if(ans.size())
            for(auto va:ans)
                printf("%d ",va);
        else
            printf("IMPOSSIBLE");
        puts("");
    }
    return 0;
}
