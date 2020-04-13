#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    string re;
    while(getline(cin,re)){
        vector<int> co(26,0);
        for(int i = 0; i < re.size();++i){
            char va = tolower(re[i]);
            if(va >= 'a' && va <= 'z')
                ++co[va-'a'];
        }
        int imp = 0;
        int sum = 0;
        vector<int> nums;
        for(int i = 0; i < 26;++i){
            if(co[i]&1) ++imp;
            sum += co[i] >> 1;
            if(co[i]>2) nums.push_back(co[i]>>1);
        }
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        if(imp > 1){
            puts("0");
            continue;
        }
        if(sum == 0){
            puts("1");continue;
        }
        ll p = 1;
        ll where = sum;
        ll k = 1;
        for(int i = 0; i < nums.size();++i){
            for(ll j = nums[i]; j >= 1ll;--j){
                if(where > 1ll) p*= where--;
                k *= j;
                ll m = __gcd(p, k);
                p /= m;
                k /= m;
            }
        }
        for(ll i = where; i > 0;--i){
            p *= i;
            ll m = __gcd(p, k);
            p /= m;
            k /= m;
        }
        printf("%lld\n",p);
    }
    return 0;
}
