#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    bool posi = 1;
    while(t--){
        int a,b,c;
        scanf(" %d %d %d",&a,&b,&c);
        if(a+b <= c || b+c <= a || c+a <= b) posi = 0;
    }
    if(posi) puts("YES");
    else puts("NO");
    return 0;
}
