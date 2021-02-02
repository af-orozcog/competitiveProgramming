#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

ll MOD = pow(2,31)-1;

int main(){
    unordered_set<int> seen;
    ll fi = 0,se = 1;
    seen.insert(0);
    seen.insert(1);
    for(int i = 2; i <= 10000;++i){
        ll temp = fi + se;
        if(temp >= MOD) temp -= MOD;
        seen.insert((int)temp);
        fi = se;
        se = temp;
    }
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        if(seen.count(n)) puts("YES");
        else puts("NO");
    }
    return 0;
}
