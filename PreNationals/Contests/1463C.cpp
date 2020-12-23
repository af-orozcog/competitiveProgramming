#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        ll times[n];
        ll posi[n];
        for(int i = 0; i < n;++i) scanf(" %lld %lld",&times[i],&posi[i]);
        ll upTo = 0;
        ll heading = 0;
        ll actual = 0;
        int ans = 0;
        for(int i = 0; i < n-1;++i){
            if(times[i] >= upTo){
                upTo = times[i] + abs(posi[i] -heading);
                heading = posi[i];
            }
            if(heading > actual){
                ll from = actual,to = actual+min(heading-actual,times[i+1]-times[i]);
                if(from <= posi[i] && posi[i] <=to) ++ans;
                actual = to;
            }
            else{
                ll to = actual, from = actual - min(actual-heading,times[i+1]-times[i]);
                if(from <= posi[i] && posi[i] <= to) ++ans;
                actual = from;
            }
        }
        if(times[n-1] >= upTo) ++ans;
        else if(heading < actual && heading <= posi[n-1] && actual >= posi[n-1]) ++ans;
        else if(heading >= posi[n-1] && actual <= posi[n-1]) ++ans;
        printf("%d\n",ans);
    }
    return 0;
}
