#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

ll a,b,c;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        cin >> a >> b >> c;
        if(a > c)
            puts("-1 1");
        else if(a*b <= c && b != 1){
            puts("1 -1");
        }
        else if(a*b > c){
            if(a == c)
                cout << -1 << " " << b << "\n";
            else
                cout << 1 << " " << b << "\n";
        }
        else if(a*b == c && b == 1){
            puts("-1 -1");
        }
    }
    return 0;
}
