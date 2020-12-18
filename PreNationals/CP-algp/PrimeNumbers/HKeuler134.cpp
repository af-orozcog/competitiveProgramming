#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll powers[] = {1,10,100,1000,10000,100000,1000000,1000000,100000000,1000000000};

ll gcd(ll a, ll b, ll &x, ll &y){
    if(b == 0){
        x = 1, y = 0;
        return a;
    }
    ll x1,y1;
    ll g = gcd(b,a%b,x1,y1);
    x = y1;
    y = x1-(a/b)*y1;
    return g;
}

void shift(ll &x, ll b, ll g,ll cnt){
    x += cnt*(b/g);
}

ll findSolution(ll a, ll b, ll c){
    ll x,y;
    ll g = gcd(a,b,x,y);
    x *= c/g;
    shift(x,b,g,(-x*g)/b);
    if(x <= 0) x += b/g;
    return x;
}

ll findNumber(ll first, ll second){
    string check = to_string(first);
    ll imp = findSolution(powers[check.size()],second,second-first)*powers[check.size()];
    return imp + first;
}

ll upTo = 31622;
vector<ll> primes;
bitset<31623> posi;

void init(){
    posi.set();
    posi[0] = posi[1] = 0;
    for(ll i = 2; i <= upTo;++i){
        if(posi[i]){
            primes.push_back(i);
            for(ll j = i*i; j <= upTo;j+=i) posi[j] = 0;
        }
    }
}

vector<ll> temp;

int main(){
    init();
    int t;
    scanf(" %d",&t);
    while(t--){
        temp.clear();
        ll L,R;
        scanf(" %lld %lld",&L,&R);
        cout << L << " " << R << "\n";
        vector<bool> isPrime(R+10000 - L + 1, true);
        for (ll i : primes)
            for (ll j = max(i * i, (L + i - 1) / i * i); j <= R+10000; j += i)
                isPrime[j - L] = false;
        if (L == 1)
            isPrime[0] = false;
        ll ans = 0;
        for(ll i = 0; i < isPrime.size();++i){
            if(isPrime[i]){
                if(temp.size()){
                    if(temp.back() > R) break;
                    ans += findNumber(temp.back(),i+L);
                    temp.pop_back();
                }
                temp.push_back(i+L);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
