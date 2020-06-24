#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        if(n < 4) printf("%d\n",4-(n%4));
        else printf("%d\n",n&1);
    }
    return 0;
}
