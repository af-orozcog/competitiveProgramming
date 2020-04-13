#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string re;
        cin >> re;
        ll MaW = 0,MaE = 0,MaU = 0,MaD = 0;
        ll whenWF,whenEF,whenUF,whenDF;
        whenDF = whenEF = whenUF = whenWF = 0;
        ll whenWS,whenES,whenUS,whenDS;
        whenDS = whenES = whenUS = whenWS = 0;
        ll x = 0,y = 0;
        ll i = 0;
        for(auto va:re){
            if(va == 'W'){
                ++y;
                if(MaU < y) MaU = y, whenUF = i;
                if(MaD > y) MaD = y, whenDF = i;
                if(MaU == y) MaU = y, whenUS = i;
                if(MaD == y) MaD = y, whenDS = i;
            }else if(va == 'S'){
                --y;
                if(MaU < y) MaU = y, whenUF = i;
                if(MaD > y) MaD = y, whenDF = i;
                if(MaU == y) MaU = y, whenUS = i;
                if(MaD == y) MaD = y, whenDS = i;
            }else if(va == 'A'){
                --x;
                if(MaW > x) MaW = x, whenWF = i;
                if(MaE < x) MaE = x, whenEF = i;
                if(MaW == x) MaW = x, whenWS = i;
                if(MaE == x) MaE = x, whenES = i;
            }
            else{
                ++x;
                if(MaW > x) MaW = x, whenWF = i;
                if(MaE < x) MaE = x, whenEF = i;
                if(MaW == x) MaW = x, whenWS = i;
                if(MaE == x) MaE = x, whenES = i;
            }
            ++i;
        }
        ll ans = (abs(MaE-MaW)+1ll)*(abs(MaU-MaD)+1ll);
        if(whenWF > whenES && (MaE != 0 || MaW < -1))
            ans = min((abs(MaE-MaW))*(abs(MaU-MaD)+1ll),ans);
        if(whenEF > whenWS && (MaW != 0 || MaE > 1))
            ans = min((abs(MaE-MaW))*(abs(MaU-MaD)+1ll),ans);
        if(whenUF > whenDS && (MaD != 0 || MaU > 1))
            ans = min((abs(MaE-MaW)+1ll)*(abs(MaU-MaD)),ans);
        if(whenDF > whenUS && (MaU != 0 || MaD < -1))
            ans = min((abs(MaE-MaW)+1ll)*(abs(MaU-MaD)),ans);
        printf("%lld\n",ans);
    }
    return 0;
}
