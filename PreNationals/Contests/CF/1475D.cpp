#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        ll n,m;
        scanf(" %lld %lld",&n,&m);
        vector<int> ones,twos;
        vector<int> all(n);
        for(int i = 0; i < n;++i) scanf(" %d",&all[i]);
        for(int i = 0; i < n;++i){
            int va; scanf(" %d",&va);
            if(va == 1) ones.push_back(all[i]);
            else twos.push_back(all[i]);
        }
        sort(ones.begin(),ones.end()); sort(twos.begin(),twos.end());
        reverse(ones.begin(),ones.end());reverse(twos.begin(),twos.end());
        int left = m;
        int i = 0, j = 0;
        ll cost = 0;
        while(left > 0 && (i < ones.size() || j < twos.size())){
            if(j == twos.size()){
                left -= ones[i];++i;++cost;
            }
            else if(i == ones.size()){
                left -= twos[j];++j;cost+=2;
            }
            else if(ones[i] >= left){
                left -= ones[i];++i;++cost;
            }
            else if(i < ones.size() && i+1 < ones.size() && ones[i]+ones[i+1] >= twos[j]){
                left -= ones[i] + ones[i+1];i+=2;cost += 2;
            }
            else if(i < ones.size() && ones[i] >= twos[j]){
                left -= ones[i];++i;++cost;
            }
            else{
                left -= twos[j];++j;cost+=2;
            }
        }
        if(left <= 0) printf("%lld\n",cost);
        else puts("-1");
    }
    return 0;
}
