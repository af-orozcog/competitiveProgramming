#include<bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN 100002

// stores smallest prime factor for every number
int spf[MAXN];

// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
    spf[1] = 1;
    for (ll i=2; i<MAXN; i++)

        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;

    // separately marking spf for every even
    // number as 2
    for (ll i=4; i<MAXN; i+=2)
        spf[i] = 2;

    for (ll i=3; i*i<MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (ll j=i*i; j<MAXN; j+=i)

                // marking spf[j] if it is not
                // previously marked
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}

// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
vector<ll> getFactorization(ll x)
{
    vector<ll> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

int main(){
    int t;
    scanf(" %d",&t);
    sieve();
    while(t--){
        int n,m,q;
        scanf( " %d %d %d",&n,&m,&q);
        while(q--){
            int r;scanf(" %d",&r);
            int co[n+1];
            memset(co,0,sizeof(co));
            for(int i = r+1; i<= n;++i){
                vector<ll> an = getFactorization(i);
                for(auto va:an)
                    co[va] += i;
            }
            for(int i = 2; i <= (n-r);++i){
                vector<ll> an = getFactorization(i);
                for(auto va: an)
                    co[va] -= i;
            }
            ll ans = 1;
            for(int i = 2; i <= n;++i){
                ans *= power(i,co[i],m);
                ans = ans % m;
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
