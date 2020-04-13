#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define EPS 1e-9
using namespace std;
typedef pair<ll,ll> pi;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        ld ma = 0.0;
        int who;
        for(int i = 0; i < n;++i){
            ld a,b,c;
            cin >> a >> b >> c;
            //cout << a << " " << b << " " << c <<"\n";
            ld r = b/(a*(ld)2.0);
            a = a*(-1.0);
            ld ans = a*r*r + b*r + c;
           // cout << ans << endl;
            if(ans - ma > EPS) ma = ans, who = i+1;
        }
        printf("%d\n",who);
    }
    return 0;
}

