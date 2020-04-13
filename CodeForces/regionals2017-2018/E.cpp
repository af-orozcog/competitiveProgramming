#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll power(ll x, ll y,  ll p)
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

string re;
int num;
string ans;

int dp[1003][1003];

bool smal(int i, ll res){
    if(i == re.size()){
        if(!res) return dp[i][res] = 1;
        return dp[i][res] = 0;
    }
    if(dp[i][res] != -1) return dp[i][res];
    int posi = 0;
    if(re[i] != '?'){
        res += ((re[i]-'0')*power(10,(int)re.size()-1-i,num))%num;
        res = res % num;
        posi = smal(i+1,res);
        return dp[i][res] = posi;
    }
    for(int j = 0; j < 10 &&!posi;++j){
        if(i == 0 && j == 0)continue;
        ll neRes = (res + (j*power(10,(int)re.size()-1-i,num))%num)%num;
        posi = smal(i+1,neRes);
        if(posi) ans[i] = '0'+j;
    }
    return dp[i][res] = posi;
}

int main(){
    memset(dp,-1,sizeof(dp));
    cin >> re >> num;
    bool po = smal(0, 0);
    if(!po) cout << "*" << endl;
    else{
        string ans = "";
        ll modulo = 0;
        for(int i = 0; i < re.size();++i){
            for(int j = 0; j < 10;++j){
                if(re[i] != '?'){
                    ans += re[i];
                    modulo = (modulo + ((re[i]-'0')*power(10,(int)re.size()-1-i,num))%num)%num;
                    break;
                }
                if(dp[i+1][modulo] != -1 && dp[i+1][modulo] == 1){
                    modulo = (modulo + (j*power(10,(int)re.size()-1-i,num))%num)%num;
                    ans += ('0'+j);
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
