#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,n;
    scanf(" %d %d %d",&a,&b,&n);
    int i = b, j = 0;
    int ans = 1;
    while(i < n){
        ans += 2;
        i += b-(a);
    }
    printf("%d\n",ans);
    return 0;
}
