#include<bits/stdc++.h>
using namespace std;

int getAns(int n){
    if(n == 1) return 0;
    int ans = n;
    int upTo = sqrt(n);
    for(int i = 2; i <= upTo;++i){
        if(n % i == 0){
            ans -= ans/i;
            while(n % i == 0) n /= i;
        }
    }

    if(n != 1) ans -= ans/n;

    return ans;
}

int main(){
    int n;
    while(scanf(" %d",&n) == 1 && n){
        printf("%d\n",getAns(n));
    }
    return 0;
}
