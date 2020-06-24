#include<bits/stdc++.h>
#define ld long double
using namespace std;

ld power(ld x, unsigned int y)
{
    ld res = 1.0;     // Initialize result

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = res*x;

        // y must be even now
        y = y>>1; // y = y/2
        x = x*x;  // Change x to x^2
    }
    return res;
}

int main(){
    int t;
    scanf(" %d",&t);
    int cas = 1;
    while(t--){
        int w,h,l,u,r,d;
        scanf(" %d %d %d %d %d %d",&w,&h,&l,&u,&r,&d);
        int ne1D = d+1;
        int ne1R = l-1;

    }
}
