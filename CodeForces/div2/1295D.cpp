#include<iostream>
#include<set>
#define ll long long
#define MAXN 100020
using namespace std;

ll gcd(ll a, ll b){
    return b == 0ll? a: gcd(b,a%b);
}

ll lcm(ll a, ll b){
    return (a/(gcd(a,b)))*b;
}

ll sqr(ll va){
    ll lo = 1, hi = 1000000000, ans;
    while(lo <= hi){
        ll mid = (hi+lo)>>1;
        if(mid*mid <= va){ans = mid;lo = mid +1ll;}
        else hi = mid -1ll;
    }
    return ans;
}

set<ll> getFactorization(ll va){
    set<ll> ans;
    ll to = sqr(va);
    for(ll i = 2; i <= to && va != 1;++i){
        while(va % i == 0){
            ans.insert(i);
            va /= i;
        }
    }
    if(va!= 1) ans.insert(va);
    return ans;
}

ll more(set<ll> &noCoun, ll imp1,ll imp2,ll up, ll imp){
    ll to = sqr(imp1);
    ll ans = 0;
    for(ll i = 2; i <= to;++i){
        if(imp1 % i == 0){
        	int co = i,ma = 0;
        	for(auto it = noCoun.begin(); it != noCoun.end() && co != 1;++it){
        		if(co % (*it) == 0) co/= (*it),++ma;
        	}
           	if(co == 1 && ma > 1){
           		//cout << i << endl;
            	ans += (up/(i*imp)) - ((imp2-1)/(i*imp));
	            --ans;
	        }
            ll ot = imp1 / i;
           // di = lcm(ot,imp);
	        co = ot,ma = 0;
        	for(auto it = noCoun.begin(); it != noCoun.end() && co != 1;++it){
        		if(co % (*it) == 0) co/= (*it),++ma;
        	}
	        if(co == 1 && ma > 1){
	        	//cout << ot << endl;
            	ans += (up/(ot*imp)) - ((imp2-1)/(ot*imp));
            	--ans;
            }
        }
    }
    return ans;
}

int main(){
    int t;
    cin>> t;
    while(t--){
        ll a,m;
        cin>> a >> m;
        ll imp = gcd(a,m);
        ll who1 = m/imp, who2 = a/imp;
        set<ll> see = getFactorization(who1);
        ll les = 1;
        ll up = m-imp + a;
        for(auto va:see){
            les += (up/(va*imp)) - ((a-1)/(va*imp));
            --les;
        }
        if(see.size() > 1)
        	les -= more(see,who1,a,up,imp);
        printf("%lld\n",who1-les);
    }
    return 0;
}
