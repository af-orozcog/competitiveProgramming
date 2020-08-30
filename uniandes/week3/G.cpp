#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,k;
        scanf(" %d %d",&n,&k);
        int original[1<<n];
        vector<pair<int,int>> nums(1<<n);
        map<int,vector<int>> won;
        for(int i = 0; i < (1<<n);++i){
            scanf(" %d",&original[i]);
            nums[i] = {i,original[i]};
        }
        while((int)nums.size() > 1){
            vector<pair<int,int>> temp;
            for(int i = 0; i < nums.size();i+=2){
                if(nums[i].second >= nums[i+1].second){
                    temp.push_back(nums[i]);
                    temp.back().second -= nums[i+1].second;
                    won[temp.back().first].push_back(nums[i+1].first);
                }else{
                    temp.push_back(nums[i+1]);
                    temp.back().second -= nums[i].second;
                    won[temp.back().first].push_back(nums[i].first);
                }
            }
            for(int i = 0; i < temp.size();++i){
                temp[i].second = min(temp[i].second+k,original[temp[i].first]);
            }
            nums = temp;
        }
        cout << nums[0].first+1 << "\n";
        int fi = 0;
        for(auto va: won[nums[0].first]){
            if(fi) cout << " ";
            cout << va+1;
            fi = 1;
        }
        cout << "\n";
    }
}
