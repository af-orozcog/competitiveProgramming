#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n; scanf(" %d",&n);
        int ma = 0;
        int m = 1000000002,me = 0;
        int nums[n];
        for(int i = 0; i < n;++i){
            scanf(" %d",&nums[i]);
            if(i && nums[i] == -1)  m = min(m,nums[i-1]), me = max(me,nums[i-1]);
            else if(i && nums[i-1] == -1) m = min(m,nums[i]), me = max(me,nums[i]);
            else if(i && nums[i] != -1 && nums[i-1] != -1) ma = max(ma,abs(nums[i]-nums[i-1]));
        }
        int dif = (me - m)>>1+((me-m)&1);
        printf("%d %d\n",max(ma,dif),m+dif);
    }
    return 0;
}
