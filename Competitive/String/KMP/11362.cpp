#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string vals[n];
        bool posi = 1;
        for(int i = 0; i < n;++i) cin >> vals[i];
        sort(vals,vals+n);
        for(int i = 0; i < n-1 && posi;++i)
            if(vals[i].size() <= vals[i+1].size())
                if(vals[i].substr(0,min((int)vals[i].size(),(int)vals[i+1].size())) == vals[i+1].substr(0,min((int)vals[i].size(),(int)vals[i+1].size())))
                    posi = 0;
        if(posi)cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}
