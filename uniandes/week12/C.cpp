#include<bits/stdc++.h>
using namespace std;

int main(){
    string a,b;
    cin >> a >> b;
    string ans = a;
    for(int i = 0; i < a.size();++i){
        int shift = b[i] - 'A';
        int where = (a[i]-'A'-shift);
        if(where < 0) where += 26;
        ans[i] = where + 'A';
        b += ans[i];
    }
    cout << ans << "\n";
    return 0;
}
