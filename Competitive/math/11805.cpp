#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;scanf(" %d",&t);
    int ca = 1;
    while(t--){
        int n,k,p;
        scanf(" %d %d %d",&n,&k,&p);
        --k;
        k += p;
        k = k % n;
        printf("Case %d: %d\n",ca++,k+1);
    }
    return 0;
}
