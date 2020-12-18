#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> posi;
vector<int> primes;
vector<int> paint;

int main(){
    int n;
    scanf(" %d",&n);
    if(n==1){
        puts("1\n1");
        return 0;
    }
    else if(n == 2){
        puts("1\n1 1");
        return 0;
    }
    posi.resize(n+2,1);
    posi[0] = posi[1] = 0;
    paint.resize(n+2,1);
    for(ll i = 2; i <= (ll)n+1;++i){
        if(posi[i]){
            for(ll j = i*i; j <= (ll)n+1; j += i) posi[j] = 0;
            primes.push_back((int)i);
        }
    }
    printf("%d\n",2);
    for(auto va:primes)
        paint[va] = 2;
    for(int i = 2; i <= n+1;++i)
        printf("%d ",paint[i]);
    puts("");
    return 0;
}
