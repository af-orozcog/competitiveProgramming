#include<bits/stdc++.h>
#define ll long long
using namespace std;


int divisors(int n){
    int upTo = sqrt(n);
    int ans = 0;
    for(int i = 1; i <= upTo;++i){
        if(n % i == 0){
            ++ans;
            if(n/i != i) ++ans;
        }
    }
    return ans;
}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int a,b;
        scanf(" %d %d",&a,&b);
        printf("%d\n",divisors(__gcd(a,b)));
    }
    return 0;
}
