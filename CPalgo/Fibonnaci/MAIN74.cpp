#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 2
#define M 1000000007
//estructura de una matriz.
struct matrix {
	long long m[N][N];
	matrix(){ memset(m,0,sizeof(m));}
	matrix operator *(matrix b){
		matrix c = matrix();
		for (int i = 0; i < N; ++i)
			for (int k = 0; k < N; ++k)
			    for (int j = 0; j < N; ++j)
				c.m[i][j] = (((c.m[i][j]%M) +((m[i][k]%M) * (b.m[k][j]%M))) % M);
	    	return c;
	}

};
// funcion para la matriz identidad
matrix unit(){
	matrix c = matrix();
	for(int i = 0;i<N; i++)
		c.m[i][i]=1;
	return c;
}
// fast matrix MOD pow
matrix modPow(matrix m,ll n){
  if ( n == 0 )
    return unit(); // the unit matrix - that is 1 for principal diagonal , otherwise 0
  matrix half = modPow(m,n>>1);
  matrix out = half * half;
  if ( n & 1 )
    out = out * m;
  return out;
}
int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        ll n;
        scanf(" %lld",&n);
        if(n == 0) puts("0");
        else if(n == 1) puts("2");
        else{
            matrix fib=matrix();
            matrix bs = matrix();
            fib.m[0][1]=1;
            fib.m[1][0]=1;
            fib.m[0][0]=1;
            fib = modPow(fib,n+2);
            printf("%lld\n",fib.m[0][0]);
        }
    }
    return 0;
}


