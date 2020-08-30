#include<bits/stdc++.h>
using namespace std;

int main(){
    int ans = 10;
    int k,r;
    cin >> k >> r;
    for(int i = 1; i < 10 && ans == 10;++i){
        if(k*i % 10 == r || k*i % 10 == 0)
            ans = i;
    }
    cout << ans << "\n";
    return 0;
}
