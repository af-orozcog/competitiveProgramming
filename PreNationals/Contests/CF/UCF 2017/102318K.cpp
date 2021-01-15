#include <bits/stdc++.h>
#define ll long long
using namespace std;
//#define N 2
//#define M 1000000009
//estructura de una matriz.
ll M = 997;
struct matrix {
    int N;
    ll M;
    ll **m;
    matrix(int sz=2, ll mo = 1000000009):N{sz},M{mo}{
        m = new ll*[N];
        for(int i = 0; i < N;++i)
            m[i] = new ll[N];
        for(int i = 0; i < N;++i)
            for(int j = 0; j < N;++j)
                m[i][j] = 0;
    }
    matrix operator *(matrix b){
        matrix c = matrix(N,M);
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                for (int k = 0; k < N; ++k)
                    c.m[i][j] = (((c.m[i][j]%M) +((m[i][k]%M) * (b.m[k][j]%M))) % M);
        return c;
    }
};
// funcion para la matriz identidad
matrix unit(int N = 2, ll mod = 1000000009){
    matrix c = matrix(N,mod);
    for(int i = 0;i<N; i++)
        c.m[i][i]=1;
    return c;
}
// fast matrix MOD pow
matrix modPow(matrix m,int n){
    if ( n == 0 )
        return unit(m.N,m.M); // the unit matrix - that is 1 for principal diagonal , otherwise 0
    matrix half = modPow(m,n/2);
    matrix out = half * half;
    if ( n % 2 )
        out = out * m;
    return out;
}

ll binPow(ll x, ll n, ll p){
    ll ans = 1;
    while(n){
        if(n&1) ans = (ans*x)%p;
        n >>= 1;
        x *= x;
        if(x >= p)
            x %= p;
    }
    return ans;
}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        matrix bs = matrix(50000,M);
        int n;
        scanf(" %d",&n);
        for(int i = 0; i < n;++i){
            for(int j = 0; j < 0; j < n;++i)
        }
        int vals[m];
        memset(vals,0,sizeof(vals));
        for(int i = 1; i < m;++i)
            vals[i] = k/m;
        for(int i = 1; i <= k%m;++i)
            ++vals[i];
        ll base = 0;
        for(int i = 0; i < m;++i){
            for(int j = 1; j < m;++j)
                bs.m[i][(i+j)%m] = vals[j];
            base += vals[i];
        }
        matrix see = modPow(bs,n);
        ll luk = binPow(base,n,1000000007);
        ll ans = see.m[0][0] * binPow(luk,1000000005,1000000007);
        if(ans >= M)
            ans %= M;
        printf("%lld\n",ans);
    }
    return 0;
}
