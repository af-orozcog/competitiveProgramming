#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

ll sum(vector<ll> &vals){
    ll ans = 100000000000000ll;
    for(int i = 0; i < vals.size();++i){
        ll temp = 0;
        for(int j = 0; j < vals.size();++j)
            temp += abs(vals[i]-vals[j]);
        ans = min(ans,temp);
    }
    return ans;
}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,m;
        scanf(" %d %d",&n,&m);
        ll matrix[n][m];
        for(int i = 0; i < n;++i)
            for(int j = 0; j < m;++j)
                scanf(" %lld",&matrix[i][j]);
        ll ans = 0;
        for(int i = 0,k = n-1; i <= k;++i,--k){
            for(int j = 0,q = m-1; j <= q;++j,--q){
                vector<ll> send;
                if(i == k && j == q)
                    continue;
                else if(i == k)
                    send = {matrix[i][j],matrix[i][q]};
                else if(j == q)
                    send = {matrix[i][j],matrix[k][j]};
                else
                    send = {matrix[i][j],matrix[i][q],matrix[k][j],matrix[k][q]};
                ll check = sum(send);
                //cout << "i " << i << " j " << j << " " << check << "\n";
                ans += check;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
