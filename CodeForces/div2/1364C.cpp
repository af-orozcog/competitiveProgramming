#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf(" %d",&n);
    int nums[n];
    set<int> imp;
    for(int i = 0; i < n;++i){
        scanf(" %d",&nums[i]);
        imp.insert(nums[i]);
    }
    int next = 0;
    queue<int> debt;
    vector<int> ans(n,-1);
    int where = 0;
    bool posi = 1;
    for(int i = 0; i < n && posi; ++i){
        imp.erase(nums[i]);
        if(debt.size() && debt.front() < nums[i]){
            ans[i] = debt.front();
            debt.pop();
            if(debt.size()) next = debt.front();
            else next = where;
        }
        else{
            if(where == nums[i]){
                debt.push(where);
                ++where;
                while(imp.count(where)){
                    debt.push(where);
                    ++where;
                }
            }
            else{
                while(imp.count(where)){
                    debt.push(where);
                    ++where;
                }
            }
            ans[i] = where++;
            if(!debt.size()) next = where;
        }
        if(next != nums[i]) posi = 0;
    }
    if(!posi){
        puts("-1");
        return 0;
    }
    for(int i = 0; i < n;++i)printf("%d ",ans[i]);
    puts("");
    return 0;
}
