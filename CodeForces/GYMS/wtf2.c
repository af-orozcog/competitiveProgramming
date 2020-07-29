#include<stdio.h>
#define max(x,y)(x > y?x:y)

int main(){
    int n;
    scanf(" %d ",&n);
    int nums[n];
    for(int i = 0; i < n;++i) scanf(" %d",&nums[i]);
    int ans = 0;
    for(int i = 0;i < n;++i){
        int temp = 0;
        for(int j = i; j < n;++j){
            temp += nums[j];
            printf("%d %d %d\n",temp*(j-i+1),i,j);
            ans = max(temp*(j-i+1),ans);
        }
    }
    printf("%d\n",ans);
    return 0;
}
