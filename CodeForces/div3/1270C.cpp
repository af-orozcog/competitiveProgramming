#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        ll sum = 0;
        ll xo = 0;
        for(int i = 0; i < n;++i){
            ll va;cin >> va;
            sum += va; xo = xo ^ va;
        }
        if(sum == (xo<<1)) puts("0\n");
        else{
            if(sum&1){
                printf("3\n");
                ++sum;
                xo = xo ^1;
                sum += xo;
                cout << xo <<" " <<sum << " " << 1 << endl;
            }
            else{
                printf("2\n");
                sum += xo;
                cout << xo << " " << sum << endl;
            }
        }
    }
    return 0;
}
