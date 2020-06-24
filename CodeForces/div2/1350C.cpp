#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define MAXN   200001
typedef pair<int,int> pi;

int spf[MAXN];

void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
        spf[i] = i;

    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;

    for (int i=3; i*i<MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (int j=i*i; j<MAXN; j+=i)

                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}

void getFactorization(int x, map<int,pair<int,pi>> &imp, map<int,int> &co)
{
    map<int,int> fr;
    while (x != 1)
    {
        ++fr[spf[x]];
        x = x / spf[x];
    }
    for(auto va:fr){
        pair<int,pi> see = imp[va.first];
        if(va.second == see.second.first)
            ++see.second.second;
        if(va.second > see.second.first)
            see.first = min(see.first,va.second);
        else if(va.second < see.second.first){
            see.first = see.second.first;
            see.second.first = va.second;
            see.second.second = 1;
        }
        imp[va.first] = see;
        ++co[va.first];
    }
}

bool isPrime(int x){
    return spf[x] == x;
}

ll power(ll x, ll y)
{
    ll res = 1;     // Initialize result

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = res*x;

        // y must be even now
        y = y>>1; // y = y/2
        x = x*x;  // Change x to x^2
    }
    return res;
}


int main(){
    sieve();
    int n;
    scanf(" %d",&n);
    if(n == 1){
        int va; scanf(" %d",&va);
        printf("%d\n",va);
        return 0;
    }
    map<int,pair<int,pi>> imp;
    for(int i = 2; i < MAXN;++i)
        if(isPrime(i))imp[i] = {0,{10000000,0}};
    map<int,int> co;
    for(int i = 0; i < n;++i){
        int va; scanf(" %d",&va);
        getFactorization(va,imp,co);
    }
    ll ans = 1;
    for(auto va:co){
        if(va.second < n -1) continue;
        if(va.second != n)
            ans *= power(va.first,imp[va.first].second.first);
        else{
            if(imp[va.first].second.second > 1)
                ans *= power(va.first,imp[va.first].second.first);
            else{
                if(imp[va.first].first == 10000000)
                    ans *= power(va.first,imp[va.first].second.first);
                else
                    ans *= power(va.first,imp[va.first].first);
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
