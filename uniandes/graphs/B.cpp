#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,t;
    scanf(" %d %d",&n,&t);
    int nums1[n],nums2[n];
    for(int i = 0; i < n;++i) scanf(" %d",&nums1[i]);
    for(int i = 0; i < n;++i) scanf(" %d",&nums2[i]);
    if(!nums1[0]){
        puts("NO");
        return 0;
    }
    bool posi = nums1[t-1];
    for(int i = t; i < n && !posi;++i){
        if(nums1[i] && nums2[i] && nums2[t-1])
            posi = 1;
    }
    if(posi)
        puts("YES");
    else
        puts("NO");
    return 0;
}
