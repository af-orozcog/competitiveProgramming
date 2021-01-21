#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    scanf(" %d",&n);
    int nums[n];
    set<pair<int,int>> seen;
    map<int,set<int>> values;
    for(int i = 0; i < n;++i){
        scanf(" %d",&nums[i]);
        seen.insert({i,nums[i]});
        values[nums[i]].insert(i);
    }
    int m;
    scanf(" %d",&m);
    set<int> altered;
    while(m--){
        int color;
        scanf(" %d",&color);
        if(!values.count(color)) continue;
        int left = (*values[color].begin());
        int right = (*values[color].rbegin());
        vector<set<pair<int,int>>::iterator> toDelete;
        altered.insert(color);
        for(auto it = seen.upper_bound({left,color}); (*it).first < right;++it){
            toDelete.push_back(it);
            int toColor = (*it).second;
            int place = (*it).first;
            values[toColor].erase(place);
            if(!values[toColor].size())
                values.erase(toColor);
        }
        for(auto &va:toDelete){
            seen.erase(va);
        }
    }
    for(auto &va:values){
        if(!altered.count(va.first)){
            for(auto pos:va.second)
                nums[pos] = va.first;
        }
        else{
            int left = (*va.second.begin());
            int right = (*va.second.rbegin());
            for(int i = left; i <= right;++i)
                nums[i] = va.first;
        }
    }
    for(int i = 0; i < n;++i)
        printf("%d ",nums[i]);
    puts("");
    return 0;
}
