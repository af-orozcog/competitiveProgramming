#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        int top = n-1;
        int lo = (n>>1)+1;
        printf("%d\n",max(n-lo,0));
    }
    return 0;
}
