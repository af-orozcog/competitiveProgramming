/**
* R.I.P KOBE
*/
#include<bits/stdc++.h>
#define ll long long

using namespace std;

int co[31];

void coun(int num){
    for(int i = 0; num; ++i){
        if(num&1) ++co[i];
        num = num >> 1;
    }
}

int main(){
    int n;
    scanf(" %d",&n);
    int nums[n];
    for(int i = 0; i < n;++i){
        scanf(" %d",&nums[i]);
        coun(nums[i]);
    }
    int look = 0;
    for(int i = 0; i < 31;++i)
        if(co[i] == 1) look = look | (1 << i);
    int selected = 0;
    int realVal = -1;
    for(int i = 0; i < n;++i)
        if((nums[i] & look) > selected) selected = (nums[i] & look), realVal = nums[i];
    if(selected != 0)
        printf("%d ",realVal);
    for(int i = 0; i < n;++i){
        if(nums[i] != realVal) printf("%d ",nums[i]);
    }
    puts("");
    return 0;
}
