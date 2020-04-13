#include<bits/stdc++.h>
#define ld long double
#define EPS 1e-8
using namespace std;


bool comp(pair<int,pair<int,ld>> &a,pair<int,pair<int,ld>> &b){
    if(a.second.second - b.second.second > EPS) return 1;
    return 0;
}
ld di = 10000000.0;
ld one = 1.0;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,pair<int,ld>>> nums(n);
        for(int i = 0; i < n;++i){
            cin >> nums[i].first >>nums[i].second.first >> nums[i].second.second;
            nums[i].second.second /= di;
        }
        ld imp;
        imp = (one-nums[0].second.second);
        for(int i = 1; i < n;++i)
            imp = imp*(one-nums[i].second.second);
        for(int i = 0; i < n;++i){
            if(nums[i].second.second == 0) continue;
            nums[i].second.second = (imp/(one-nums[i].second.second))*nums[i].second.second;
        }
        sort(nums.begin(),nums.end(),comp);
        vector<int> acum1(n),acum2(n);
        acum1[0] = nums[0].first;
        for(int i = 1; i < n;++i)
            acum1[i] = acum1[i-1]+nums[i].first;
        acum2[n-1] = nums[n-1].second.first;
        for(int i = n-2;i > -1;--i)
            acum2[i] = acum2[i+1] + nums[i].second.first;
        map<int,ld> fr;
        for(int i = 0; i < n;++i){
            int va = acum1[i];
            if(i != n-1) va += acum2[i+1];
            fr[va] += nums[i].second.second;
        }
        ld expected = 0.0;
        for(auto va:fr){
            expected += (ld)va.first * va.second;
        }
        cout << setprecision(7) << expected << "\n";
    }
    return 0;
}
