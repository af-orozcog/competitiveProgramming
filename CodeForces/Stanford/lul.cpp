#include<bits/stdc++.h>
#define MAX_N 2
#define ll long long
using namespace std;

struct Matrix { ll mat[MAX_N][MAX_N];};
const ll M = 1000000009;

Matrix matMul(Matrix a, Matrix b){
    Matrix ans;int i,j,k;
    for(int i = 0; i < MAX_N;++i)
        for(int j = 0; j < MAX_N;++j)
            for(ans.mat[i][j] = k = 0;k < MAX_N;++k)
                ans.mat[i][j] += (a.mat[i][k] * b.mat[k][j])%M;
    return ans;
}

Matrix matPow(Matrix base, ll p){
    Matrix ans; int i, j;
    for(int i = 0; i < MAX_N;++i) for(j = 0; j < MAX_N;++j)
        ans.mat[i][j] = (i==j);
    while(p){
        if(p & 1) ans = matMul(ans,base);
        base = matMul(base,base);
        p >>= 1;
    }
    return ans;
}

ll fastExp(ll base, ll p){
    if(p == 0) return 1;
    else if(p == 1) return base;
    else{
        int res = fastExp(base,p>>1); res*=res;
        res = res % M;
        if(p&1) res *= base;
        res = res % M;
        return res;
    }
}

int main(){
    Matrix fib;
    fib.mat[0][0] = fib.mat[0][1] = fib.mat[1][0] =1;
    fib.mat[1][1] = 0;
    ll k,n;
    while(scanf(" %lld %lld",&k,&n) == 2 && (k!= 0 || n != 0)){
        Matrix ans = matPow(fib,n);
        Matrix les;
        les.mat[0][0] = les.mat[0][1] = les.mat[1][1] = les.mat[1][0] = 0;
        if(n-k > 1ll) les = matPow(fib,(n-k)+1);
        printf("%d\n",ans.mat[0][0]-);
    }
    return 0;
}
