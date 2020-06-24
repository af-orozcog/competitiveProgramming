#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string re;
        cin >> re;
        string ans = re.substr(0,2);
        for(int i = 2; i < re.size();++i){
            ans += re[i];
            if(i%2==0) ans.pop_back();
        }
        cout << ans << "\n";
    }
    return 0;
}
