#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        map<ll,int> values;
        vector<ll> sta;
        int q;
        scanf(" %d",&q);
        while(q--){
            int op;
            scanf(" %d",&op);
            if(op == 1){
                ll val; scanf(" %lld",&val);
                ++values[val];
                sta.push_back(val);
            }
            else if(op == 2){
                if(sta.size()){
                    --values[sta.back()];
                    if(values[sta.back()] == 0)
                        values.erase(sta.back());
                    sta.pop_back();
                }
            }
            else{
                if(!values.size())
                    puts("Empty!");
                else{
                    ll ma = (*values.rbegin()).first;
                    ll mi = (*values.begin()).first;
                    printf("%lld\n",ma-mi);
                }
            }
        }
    }
    return 0;
}
