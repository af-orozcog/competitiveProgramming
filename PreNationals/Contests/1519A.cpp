#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int r,b,d;
        scanf(" %d %d %d",&r,&b,&d);
        if(r > b) swap(r,b);
        if(d != 0 && ((b/(d+1))+(b%(d+1)!= 0)) <= r) puts("YES");
        else if(d == 0 && r-b == 0) puts("YES");
        else puts("NO");
    }
    return 0;
}
