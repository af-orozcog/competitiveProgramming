#include<bits/stdc++.h>
using namespace std;

bool answer(vector<int> &see, int sz){
    vector<int> kmp(see.size(),0);
    int border = 0;
    for(int i = 1; i < see.size();++i){
        while(border && see[i] != see[border])
            border = kmp[border-1];
        if(see[i] == see[border])
            ++border;
        kmp[i] = border;
        if(border == sz)return 1;
    }
    return false;
}

int main(){
    int n;
    scanf(" %d",&n);
    vector<int> nums1(n),nums2(n);
    for(int i = 0; i < n;++i)
        scanf(" %d",&nums1[i]);
    for(int i = 0; i < n;++i)
        scanf(" %d",&nums2[i]);
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());
    for(int i = 0; i < n;++i)
        nums2.push_back(nums2[i]);
    vector<int> use1,use2;
    for(int i = 1; i < n;++i)
        use1.push_back(nums1[i]-nums1[i-1]);
    for(int i = 1; i < 2*n;++i){
        use2.push_back(nums2[i]-nums2[i-1]);
        if(use2.back() < 0)
            use2.back() += 360000;
    }
    use1.push_back(-1);
    for(auto va:use2)
        use1.push_back(va);
    bool ans = answer(use1,n-1);
    if(ans)puts("possible");
    else puts("impossible");
    return 0;
}
