#include<bits/stdc++.h>

using namespace std;

int co[3*10000000];
int nums[3*1000000];

const int M = 3*10000000;

int main(){
    int n,m,q;
    scanf(" %d %d %d",&n,&m,&q);
    for(int i = 0; i < m;++i){
        int va; scanf(" %d",&va);
        ++co[va];
        nums[i] = va;
    }
    for(int i = m;i < n;++i){
        nums[i] = (nums[i-m]+nums[i-m+1])% M;
        ++co[nums[i]];
    }
    for(int i = 0, j = 0; i < n && j < M;){
        if(co[j]){nums[i++] = j,--co[j];}
        else ++j;
    }
    for(int i = 0; i < q;++i){
        int va;scanf(" %d",&va);
        --va;
        printf("%d\n",nums[va]);
    }
    return 0;
}
