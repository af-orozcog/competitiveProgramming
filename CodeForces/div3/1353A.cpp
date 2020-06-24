//hope to have a good performance to show Marie :)
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,m;
        scanf(" %d %d",&n,&m);
        if(n == 1)
            puts("0");
        else if(n == 2)
            printf("%d\n",m);
        else
            printf("%d\n",m<<1);
    }
    return 0;
}
