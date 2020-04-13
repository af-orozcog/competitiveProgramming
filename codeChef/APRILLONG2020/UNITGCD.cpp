#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        if(n == 1){
            puts("1\n1 1");
            continue;
        }
        if(n == 2){
            puts("2\n2 1 2");
            continue;
        }
        printf("%d\n",n>>1);
        printf("3 1 2 3\n");
        for(int i = 4; i <= n;i+=2){
            if(i + 1 <= n)
                printf("2 %d %d\n",i,i+1);
            else printf("1 %d\n",i);
        }
    }
    return 0;
}
