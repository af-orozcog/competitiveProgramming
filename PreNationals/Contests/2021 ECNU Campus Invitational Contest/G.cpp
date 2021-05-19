#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int a,b;
        scanf(" %d %d",&a,&b);
        if(a == b) puts("2");
        else if(b == 1) printf("%d\n",a+1);
        else puts("3");
    }
    return 0;
}
