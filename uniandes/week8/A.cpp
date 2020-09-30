#include<bits/stdc++.h>
using namespace std;

int main(){
    int nums1[2],nums2[2],n;
    scanf(" %d %d %d %d %d",&nums1[0],&nums1[1],&nums2[0],&nums2[1],&n);
    if(nums[0] > nums[1]){swap(nums1[0],nums1[1]);swap(nums2[0],nums2[1]);}
    int max = 0;
    int min = 0;
    int temp = nums2[0];
    while(temp > nums[0]){
        ++max;
        temp -= nums[0];
    }

    return 0;
}
