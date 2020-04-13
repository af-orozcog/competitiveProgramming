#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll M = 1000000007;


int main(){
    string re;
    cin >> re;
    ll lastB = re.size();
    ll acum = 0;
    ll ans = 0;
    for(int i = re.size()-1;i > -1;--i){
        if(re[i] == 'b'){
            acum += (ll)lastB - (ll)i - (ll)1;
            lastB = i;
        }
        else if(re[i] == 'a'){
            ++ans;
            if(lastB != (int)re.size())
                ans += acum;
        }
        ans = ans % M;
    }
    printf("%lld\n",ans);
    return 0;
}
