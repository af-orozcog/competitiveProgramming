#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n,m; ll k;
    scanf(" %d %d %lld",&n,&m,&k);
    ll nums1[n],nums2[m];
    for(int i = 0; i < n;++i){
        scanf(" %lld",&nums1[i]);
        if(i > 0){
            if(nums1[i]+nums1[i-1]>1000000000ll) nums1[i] = 1000000001;
            else nums1[i] += nums1[i-1];
        }
    }
    for(int i = 0; i < m;++i){
        scanf(" %lld",&nums2[i]);
        if(i > 0){
            if(nums2[i]+nums2[i-1]>1000000000ll) nums2[i] = 1000000001ll;
            else nums2[i] += nums2[i-1];
        }
    }
    int books = 0;
    for(int i = 0; i < n;++i){
        if(nums1[i] > k)break;
        int lo = 0, hi = m,ans = 0;
        while(lo<= hi){
            int mid = (hi+lo)>>1;
            if(nums2[mid] <= k-nums1[i]) ans = mid+1,lo = mid +1;
            else hi = mid -1;
        }
        books = max(books,i+1 +ans);
    }
    for(int i = 0; i < m;++i){
        if(nums2[i] > k)break;
        int lo = 0, hi = n,ans = 0;
        while(lo<= hi){
            int mid = (hi+lo)>>1;
            if(nums1[mid] <= k-nums2[i]) ans = mid+1,lo = mid +1;
            else hi = mid -1;
        }
        books = max(books,i+1+ans);
    }
    printf("%d\n",books);
    return 0;
}
