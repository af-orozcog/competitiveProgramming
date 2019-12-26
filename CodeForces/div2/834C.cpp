#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    int n;
    scanf(" %d",&n);
    ll a,b;
    while(n--){
        cin >> a >> b;
        ll check = a*b;
       // cout << check << endl;
        ll va = cbrt(check);
        if(va*va*va != check) puts("No");
        if(a%va == 0 && b%va == 0) puts("Yes");
        else puts("No");
    }
    return 0;
}
