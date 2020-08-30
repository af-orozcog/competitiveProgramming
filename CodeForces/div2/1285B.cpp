#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        ll ma1 = -1000000000000000ll;
        ll temp = 0;
        int le,ri;
        int tempLe = 0;
        ll sum = 0;
        for(int i = 0; i < n;++i){
            ll va; scanf(" %lld",&va);
            sum += va;
            temp += va;
            if(temp < 0ll){
                if(temp > ma1)
                    ma1 = temp,le = ri = 0;
                temp = 0;
                tempLe = i+1;
                continue;
            }
            if(temp == 0)
                tempLe = i;
            if(temp > ma1){
                ma1 = temp;
                le = tempLe;
                ri = i;
            }
        }
        if(sum <= ma1 && (le != 0 || ri != n-1))
            puts("NO");
        else
            puts("YES");
    }
    return 0;
}
