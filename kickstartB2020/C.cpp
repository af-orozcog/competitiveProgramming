#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll mod = 1000000000;

int main(){
    int t;
    scanf(" %d",&t);
    int cas = 1;
    while(t--){
        string re;
        cin >> re;
        int x,y;
        x = y = 1;
        vector<ll> mul;
        mul.push_back(1);
        ll movesX,movesY;
        movesX = movesY = 0;
        for(int i = 0; i < re.size();++i){
            if(re[i] > '0' && re[i] <= '9'){
                ll add = mul.back()*(ll)(re[i]-'0');
                if(add >= mod) add %= mod;
                mul.push_back(add);
            }
            else if(re[i] == '('){
                movesX *= mul[mul.size()-2];
                movesY *= mul[mul.size()-2];
                if(abs(movesX) >= mod) movesX %= mod;
                if(abs(movesY) >= mod) movesY %= mod;
                x += movesX;
                y += movesY;
                if(x <= 0) x += (int)mod;
                if(y <= 0) y += (int)mod;
                if(x > (int)mod) x -= (int)mod;
                if(y > (int)mod) y -= (int)mod;
                movesX = movesY = 0;
            }
            else if(re[i] == ')'){
                movesX *= mul.back();
                movesY *= mul.back();
                if(abs(movesX) >= mod) movesX %= mod;
                if(abs(movesY) >= mod) movesY %= mod;
                x += movesX;
                y += movesY;
                if(x <= 0) x += (int)mod;
                if(y <= 0) y += (int)mod;
                if(x > (int)mod) x -= (int)mod;
                if(y > (int)mod) y -= (int)mod;
                mul.pop_back();
                movesX = movesY = 0;
            }
            else{
                if(re[i] == 'S')++movesY;
                else if(re[i] == 'E') ++movesX;
                else if(re[i] == 'W') -- movesX;
                else if(re[i] == 'N') --movesY;
                if(abs(movesX) >= mod) movesX %= mod;
                if(abs(movesY) >= mod) movesY %= mod;
            }
        }
        x += movesX;
        y += movesY;
        if(x <= 0) x += (int)mod;
        if(y <= 0) y += (int)mod;
        if(x > (int)mod) x -= (int)mod;
        if(y > (int)mod) y -= (int)mod;
        printf("Case #%d: %d %d\n",cas++,x,y);
    }
    return 0;
}
