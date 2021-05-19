#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,q;
    scanf(" %d %d",&n,&q);
    int nums[n+1];
    nums[0] = 0;
    for(int i = 1; i <= n;++i){
        int temp;
        scanf(" %d",&temp);
        if(temp == 3|| temp == 4 || temp == 6) nums[i] = 1;
        else nums[i] = 0;
    }
    for(int i = 1; i <= n;++i) nums[i] += nums[i-1];
    while(q--){
        int l,r;
        scanf(" %d %d",&l,&r);
        printf("%d\n",nums[r]-nums[l-1]);
    }
    return 0;
}
