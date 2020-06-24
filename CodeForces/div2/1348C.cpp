#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,k;
        string ans = "";
        scanf(" %d %d",&n,&k);
        string re;
        cin >> re;
        sort(re.begin(),re.end());
        int coS = 1, coB = 1;
        int le = 0,ri = n-1;
        for(int i = 1; i < n;++i){
            if(re[i] == re[i-1])++coS,++le;
            else break;
        }
        for(int i = n-2; i > -1;--i){
            if(re[i] == re[i+1])++coB,--ri;
            else break;
        }
        int how = n - k + 1;
        if(how == n){
            cout << re << "\n";
            continue;
        }
        if(coS == coB && coS == n){
            int si = n / k;
            int r = n % k;
            if(r > si)
                cout << re.substr(0,r)<< "\n";
            else
                cout << re.substr(0,si) << "\n";
            continue;
        }
        else{
            int toTake = how-1;
            if(coB > toTake)
                cout << re.back() << "\n";
            else if(toTake > coB){
                if(re[0] < re[n-toTake-1])
                    cout << re[n-toTake-1] << "\n";
                else
                    cout << re[0] << re.substr((int)re.size()-toTake,re.size()) << "\n";
            }
            else if(toTake == coB){
                int si = coB / coS;
                int r = coB % coS;
                if(re[0] < re[n-coB-1])
                    cout <<  re[n-coB-1] << "\n";
                else
                    cout << re[0] << re.substr((int)re.size()-max(si,r),re.size()) << "\n";
            }
        }
    }
    return 0;
}
