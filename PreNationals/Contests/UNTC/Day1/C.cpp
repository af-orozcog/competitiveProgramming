#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){
    int n,m;
    scanf(" %d %d",&n,&m);
    bool pali[n][m][m];
    char matrix[n][m];
    memset(pali,0,sizeof(pali));
    for(int i = 0; i < n;++i)
        for(int j = 0; j < m;++j) scanf(" %c",&matrix[i][j]);
    for(int i = 0; i < n;++i){
        for(int j = 0; j < m;++j){
            map<char,int> parity;
            int bad = 0;
            for(int k = j; k < m;++k){
                if((++parity[matrix[i][k]]) %2) ++bad;
                else --bad;
                if(bad <= 1) pali[i][j][k] = 1;
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i < m;++i){
        int last = -1;
        for(int j = i; j < m;++j){
            for(int k = 0; k < n;++k){
                if(pali[k][i][j])
                    ans += (ll)(k-last);
                else last = k;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
