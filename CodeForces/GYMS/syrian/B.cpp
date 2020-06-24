#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int a,b;
        scanf(" %d %d",&a,&b);
        a = a&1, b = b&1;
        if(a*b == 1) puts("Hussain");
        else puts("Hasan");
    }
    return 0;
}
