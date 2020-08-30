#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int l,r;
        scanf(" %d %d",&l,&r);
        if((l<<1) > r){
            puts("-1 -1");
            continue;
        }
        printf("%d %d\n",l,l<<1);
    }
    return 0;
}
