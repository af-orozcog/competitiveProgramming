#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

int main(){
    int t;
    cin >> t;
    while(t--){
        int ans = 0;
        int available = 0;
        string see;
        cin >> see;
        for(auto let:see){
            if(let == 'U'|| let == 'M'){
                if(available)
                    --available;
                else ++ans;
            }
            else
                ++available;
        }
        cout << ans*5 << "\n";
    }
    return 0;
}
