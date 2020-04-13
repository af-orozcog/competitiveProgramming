#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int a,b;
        scanf(" %d %d",&a,&b);
        if(a % b == 0)
            puts("0");
        else{
            int div = a/b;
            int val2 = (div+1)*b;
            printf("%d\n",val2-a);
        }
    }
    return 0;
}
