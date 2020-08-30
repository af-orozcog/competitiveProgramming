#include<bits/stdc++.h>
using namespace std;

bool posi(int a,int b,int c){
    if (a + b <= c || a + c <= b || b + c <= a)
        return 0;
    return 1;
}


int main(){
    int n;
    scanf(" %d",&n);
    int nums[n];
    for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
    int ans = 0;
    for(int i = 0; i < n;++i)
        for(int j = i + 1; j < n;++j)
            for(int k = j+1; k < n;++k)
                if(nums[i] != nums[j] && nums[j] != nums[k] && nums[i] != nums[k] && posi(nums[i],nums[j],nums[k]))
                    ++ans;
    printf("%d\n",ans);
    return 0;
}
