#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        if(n&1) ++n;
        printf("%d\n",n>>1);
    }
    return 0;
}
