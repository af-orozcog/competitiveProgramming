#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;


ll L[1000004];
ll H[1000004];
ll AL,BL,CL,DL,AH,BH,CH,DH;
ll N,K,W;
ll mod = 1000000007;

int main(){
    int t;
    scanf(" %d",&t);
    int cas = 1;
    while(t--){
        scanf(" %lld %lld %lld",&N,&K,&W);
        for(int i = 0; i < K;++i)
            scanf(" %lld",&L[i]);
        scanf(" %lld %lld %lld %lld",&AL,&BL,&CL,&DL);
        for(int i = 0; i < K;++i)
            scanf(" %lld",&H[i]);
        scanf(" %lld %lld %lld %lld",&AH,&BH,&CH,&DH);
        ll ans = 0;
        ll perimeter = (W+H[0])<<1;
        ans = perimeter;
        vector<pi> last2(22,{-1,0});
        if(perimeter >= mod) ans %= mod,perimeter %= mod;
        for(ll i = 1, j = L[0]+1; i < (int)last2.size();++i,++j)
            last2[i] = {j,(j <= L[0]+W?H[0]:0)};
        vector<pi> last(2,{-1,0});
        last[1] = {H[0],L[0]};
        for(ll k = 1; k < N;++k){
            ll actH;
            ll actX;
            if(k >= K){
                actX = ((AL*last[0].second+BL*last.back().second+CL)%DL)+1ll;
                actH = ((AH*last[0].first+BH*last.back().first+CH)%DH)+1ll;
            }
            else
                actH = H[k],actX = L[k];
            vector<pi> temp(22,{-1,0});
            vector<pi> temp2;
            for(ll i = actX, j = 0; j < (ll)temp.size();++i,++j)
                temp[j].first = i;
            for(ll i = 0,j = 0; i < (ll)last2.size();++i){
                if(last2[i].first == temp[j].first)
                    temp[j++].second = last2[i].second;
            }
            temp2 = temp;
            for(ll i = 1, j = actX+1ll; i < (int)temp.size() && j <= actX+W;++i,++j){
                if(actH >= temp[i].second){
                    if(!temp[i].second) perimeter+=2ll;
                    if(perimeter >= mod) perimeter -= mod;
                    perimeter -= abs(temp[i].second-temp[i-1].second)%mod;
                    if(perimeter < 0) perimeter += mod;
                    else if(perimeter >= mod) perimeter -= mod;
                    perimeter += abs(actH-temp2[i-1].second)%mod;
                    if(perimeter >= mod) perimeter -= mod;
                    temp2[i].second = actH;
                }
            }
            perimeter += (actH)%mod;
            if(perimeter >= mod) perimeter -= mod;
            ans *= perimeter;
            if(ans >= mod) ans %= mod;
            last2.swap(temp2);
            swap(last[0],last[1]);
            last[1] = {actH,actX};
        }
        printf("Case #%d: %lld\n",cas++,ans);
    }
    return 0;
}
