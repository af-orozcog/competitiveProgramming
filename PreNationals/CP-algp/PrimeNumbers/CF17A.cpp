#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    scanf(" %d %d",&n,&k);
    vector<bool> posi(n+1,true);
    vector<int> primes;
    for(int i = 2; i <= n;++i){
        if(posi[i]){
            for(int j = i*i; j <= n;j+=i) posi[j] = 0;
            primes.push_back(i);
        }
    }
    int good = 0;
    for(int i = 1; i < primes.size();++i){
        if(primes[i]+primes[i-1]+1 <= n && posi[primes[i]+primes[i-1]+1])
            ++good;
    }
    if(good >= k) puts("YES");
    else puts("NO");
    return 0;
}
