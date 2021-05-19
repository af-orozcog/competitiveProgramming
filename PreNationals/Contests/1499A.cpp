#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,w1,w2;
        scanf(" %d %d %d",&n,&w1,&w2);
        int b1 = n-w1,b2 = n-w2;
        if(w1 > w2) swap(w1,w2);
        if(b1 > b2) swap(b1,b2);
        int w,b;
        scanf(" %d %d",&w,&b);
        int tot1 = (w1 + (w2-w1)/2);
        int tot2 = (b1 + (b2-b1)/2);
        if(tot1 >= w && tot2 >= b)
            puts("YES");
        else puts("NO");
    }
    return 0;
}
