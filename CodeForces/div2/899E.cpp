#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;

int main(){
    int n;
    scanf(" %d",&n);
    set<pi> longest;
    set<pair<int,pi>> dp;
    map<int,int> beh;
    int nums[n];
    for(int i = 0; i < n;++i){
        scanf(" %d",&nums[i]);
        auto it = dp.rbegin();
        if(it == dp.rend() || (*it).second.first != nums[i]){
            int last = -1;
            if(it != dp.rend()) last = (*it).first;
            dp.insert({i,{nums[i],1}});
            beh[i] = last;
        }
        else{
            pair<int,pi> imp1 = *it;
            dp.erase(imp1);
            ++imp1.second.second;
            dp.insert(imp1);
        }
    }
    for(auto va:dp)
        longest.insert({va.second.second,-va.first});
    int ans = 0;
    while(dp.size()){
        ++ans;
        auto imp = longest.rbegin();
        auto temp = dp.lower_bound({-(*imp).second,{0,0}});
        auto see1 = dp.lower_bound({beh[(*temp).first],{0,0}});
        auto see2 = temp;
        ++see2;
        //cout << (*imp).first << " " << (*imp).second << "\n";
        if(see1 == temp || see2 == dp.end())
            longest.erase({(*imp).first,(*imp).second});
        else {
            pair<int,int> eer = *imp;
            longest.erase(eer);
            if((*see1).second.first == (*see2).second.first){
                pair<int,pi> imp1 = *see1;
                pair<int,pi> imp2 = *see2;
                pair<int,pi> next = {-1,{-1,-1}};
                ++see2;
                if(see2 != dp.end())
                    next = *see2;
                longest.erase({imp1.second.second,-imp1.first});
                longest.erase({imp2.second.second,-imp2.first});
                dp.erase(imp2);
                dp.erase(imp1);
                if(next.first != -1)
                    beh[next.first] = imp1.first;
                imp1.second.second += imp2.second.second;
                longest.insert({imp1.second.second,-imp1.first});
                dp.insert(imp1);
            }
            else{
                pair<int,pi> imp1 = *see1;
                pair<int,pi> imp2 = *see2;
                beh[imp2.first] = imp1.first;
            }
        }
        dp.erase(temp);
    }
    printf("%d\n",ans);
    return 0;
}
