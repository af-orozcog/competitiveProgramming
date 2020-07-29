#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    string a,b;
    cin >> a >> b;
    int ans =0;
    for(int i = 0; i < a.size();++i){
        if(a[i] != b[i]) ++ans;
    }
    cout << ans << "\n";
    return 0;
}
