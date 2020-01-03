#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    scanf(" %d",&n);
    set<int> give,rece,bot;
    for(int i = 1; i <= n;++i){ give.insert(i);rece.insert(i);bot.insert(i);}
    int nums[n];
    for(int i = 1; i <= n;++i){
        int va;scanf(" %d",&va);
        if(va != 0){
            give.erase(i);
            rece.erase(va);
            nums[i-1] = va;
            bot.erase(i);bot.erase(va);
        }
    }
    for(auto va:give){
        auto it = rece.lower_bound(va+1);
        if(it == rece.end()) it = rece.begin();
        nums[va-1] = *it;
        rece.erase(it);
    }
    for(int i = 0; i < n;++i) printf("%d ",nums[i]);
    puts("");
    return 0;
}
