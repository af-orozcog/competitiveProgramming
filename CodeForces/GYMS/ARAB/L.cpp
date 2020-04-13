#include<bits/stdc++.h>
#define ll long long
using namespace std;

#define MAX 100005
#define pb push_back


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("looking.in","r",stdin);
    int t, n , k, x;
    cin>>t;
    while(t--){
        cin>>n>>k;
        int rta = 0;
        for(int i = 0; i<n; ++i){
            cin>>x;
            rta|=x;
        }
        cout<<rta<<"\n";
    }
    return 0;
}

