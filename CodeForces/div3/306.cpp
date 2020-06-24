#include<bits/stdc++.h>
using namespace std;

int where(int i, int k, vector<int> &nums){
    if(nums[i] == i) return i;
    vector<int> see = nums;
    int steps = 0;
    bool cycle = 0;
    int j = i;
    for(;steps != k && !cycle;){
        j = nums[j];
        ++steps;
        if(j == i)cycle = 1;
    }
    if(cycle){
        k = k % steps;
        steps = 0;
        j = i;
        for(;steps != k;){
            j = nums[j];
            ++steps;
        }
        return j;
    }
    else return j;
}

int main(){
    while(1){
        int n;
        scanf(" %d",&n);
        if(!n)break;
        vector<int> nums(n);
        for(int i = 0; i < n;++i) scanf("%d",&nums[i]);
        for(auto &va:nums) --va;
        while(1){
            int k;
            string re;
            cin >> k;
            cin.ignore();
            if(k == 0)break;
            getline(cin,re);
            while(re.size() < n){
                re += ' ';
            }
            vector<char> ans(re.size());
            for(int i = 0; i < n;++i){
                int inse = where(i,k,nums);
                //cout << inse << "\n";
                ans[inse] = re[i];
            }
            for(auto va:ans)printf("%c",va);
            puts("");
        }
        puts("");
    }
    return 0;
}
