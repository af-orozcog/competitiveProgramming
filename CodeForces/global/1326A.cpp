#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        if(n == 1)puts("-1");
        else{
            for(int i = 0; i < n-1;++i)printf("3");
            puts("4");
        }
    }
    return 0;
}
