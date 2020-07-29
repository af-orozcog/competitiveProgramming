#include<stdio.h>
#define max(x,y)(x > y?x:y)

int main(){
    int n;
    scanf(" %d ",&n);
    int result = 0;
    int curMax = 0;
    int left = -1;
    for(int i = 0; i < n;++i){
        int va;scanf(" %d",&va);
        curMax += va;
        if(curMax < 0){
            curMax = 0;
            left = i;
        }
        result = max(result,(i-left)*curMax);
        printf("%d %d %d\n",i,result,curMax);
    }
    printf("%d\n",result);
    return 0;
}
