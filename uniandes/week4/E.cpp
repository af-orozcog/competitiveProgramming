#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int m,n;
        scanf(" %d %d",&n,&m);
        if(n % m == 0) puts("YES");
        else puts("NO");
    }
    return 0;
}
