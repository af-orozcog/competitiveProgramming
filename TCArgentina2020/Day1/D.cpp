#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    int n,single,dou;
    cin >> n >> single >> dou;
    int ans = 0;
    for(int i = 0; i < n;++i){
        int va;
        cin >> va;
        if(va == 1){
            if(single) --single;
            else if(dou) --dou,++single;
            else ++ans;
        }
        else{
            if(dou)--dou;
            else ans+=2;
        }
    }
    cout << ans << "\n";
    return 0;
}
