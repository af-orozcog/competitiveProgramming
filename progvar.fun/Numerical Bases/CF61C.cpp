#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll decimal(char see[], ll base){
    ll ans = 0;
    int n = strlen(see);
    for(int i = 0; i < n;++i){
        ans *= base;
        if(see[i] >= 'A')
            ans += 10ll +(ll)(see[i]-'A');
        else
            ans += (ll)(see[i]-'0');
    }
    return ans;
}

char vals[] = {'M','D','X','L','C','V','I'};
ll numVals[] = {1000,500,100,50,10,5,1};

string toRoman(ll num){
    string ans = "";
    for(int i = 0; i < 7;++i){
        while(num >= numVals[i]){
            ans += vals[i];
            num -= numVals[i];
        }
    }
    return ans;
}

string toBase(ll num, ll base){
    string ans = "";
    while(num){
        ll see = (num%base);
        if(see >= 10){
            see -= 10;
            ans += ('A'+see);
        }
        else
            ans += to_string(see);
        num /= base;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    ll a;
    char b[300];
    scanf(" %lld %s",&a,b);
    char c[300];
    scanf(" %s",c);
    ll important = decimal(c,a);
    if(b[0] == 'R')
        cout << toRoman(important) << "\n";
    else
        cout << toBase(important,atoi(b)) << "\n";
    return 0;
}
