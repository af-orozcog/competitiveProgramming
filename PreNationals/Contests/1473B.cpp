#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

int lcm(int a,int b){
    int g = __gcd(a,b);
    return (a/g)*b;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string a,b;
        cin >> a >> b;
        if(a.size() < b.size())
            swap(a,b);
        int imp = lcm(a.size(),b.size());
        string see1 = a, see2 = b;
        while((int)see1.size() != imp)
            see1 += a;
        while((int)see2.size() != imp)
            see2 += b;
        if(see1 == see2)cout << see1 << "\n";
        else cout << -1 << "\n";
    }
    return 0;
}
