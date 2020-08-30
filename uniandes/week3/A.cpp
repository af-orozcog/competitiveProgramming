#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    int ans = 0;
    while(t--){
        string val;
        cin >> val;
        if(val[0] == '+'  || val.back() == '+')
            ++ans;
        else
            --ans;
    }
    cout << ans << "\n";
    return 0;
}
