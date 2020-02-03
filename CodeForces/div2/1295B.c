#include<stdio.h>


int abs(int va){
    if(va < 0) return -va;
    return va;
}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,x;
        scanf(" %d %d",&n,&x);
        char see[n+1];
        scanf(" %s",see);
        int pre[n];
        for(int i = 0; i < n;++i){
            if(i == 0)
                pre[i] = (see[i] == '0'? 1:-1);
            else
                pre[i] = (see[i] == '0'?1:-1) + pre[i-1];
        }
        if(!pre[n-1]){
            int posi = 0;
            for(int i = 0; i < n && !posi;++i)
                if(pre[i] == x) posi = 1;
            if(posi) puts("-1");
            else puts("0");
            continue;
        }
        //printf("%d\n",pre[n-1]);
        int sols = (x == 0?1:0);
        for(int i = 0; i < n;++i){
            if(x - pre[i] == 0) ++sols;
            else if(x - pre[i] > 0 && pre[n-1] > 0 && ((x-pre[i]) % (pre[n-1])) == 0) ++sols;
            else if(x - pre[i] < 0 && pre[n-1] < 0 && ((x-pre[i]) % (-pre[n-1]) == 0)) ++sols;
        }
        printf("%d\n",sols);
    }
    return 0;
}
