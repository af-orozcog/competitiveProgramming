#include<bits/stdc++.h>
#define ld long double
using namespace std;
#define EPS 1e-7

const long double PI  =3.141592653589793238463;
const long double di = 180.0;

int main(){
    ld L,W,H;
    cin >> L >> W >> H;
    ld x,y,a;
    cin >> x >> y >> a;
    a = (a*PI/di);
    ld neX = cosl(a)*H + x;
    ld neY = sinl(a)*H + y;
    if(neX > -EPS && neX < W+EPS && neY > -EPS && neY < L+EPS)
        puts("YES");
    else puts("NO");
    return 0;
}
