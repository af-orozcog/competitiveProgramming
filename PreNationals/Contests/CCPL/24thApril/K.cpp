#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;


int gcd(int a, int b){
    return b == 0? a : gcd(b,a%b);
}

int lcm(int a, int b){
    return (a/gcd(a,b))*b;
}

bool comp(const pi &a, const pi &b){
    int see = lcm(a.second,b.second);
    int check1 = a.first*(see/a.second),check2 = b.first*(see/b.second);
    return check1 < check2;
}

int main(){
    vector<pi> see;
    for(int i = 1; i < 1000;++i){
        for(int j = 1; j <= i;++j){
            if(gcd(i,j) == 1)
                see.push_back({j,i});
        }
    }
    sort(see.begin(),see.end(),comp);
    int n,k;
    while(scanf(" %d %d",&n,&k) == 2){
        for(auto &va:see){
            if(va.second <= n)
                --k;
            if(k == 0){
                printf("%d/%d\n",va.first,va.second);
                break;
            }
        }
    }
    return 0;
}
