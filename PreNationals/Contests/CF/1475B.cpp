#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool findAny(int a, int b, int c){
    int x,y,g;
    g = gcd(a,b,x,y);
    if(c % g) return 0;
    x *= (c/g);
    y *= (c/g);
    //cout << x << " " << y << "\n";
    int k = (-x/b)*(g);
    //cout << k << "\n";
    if(x + (k*(b/g)) < 0) ++k;
    //cout << k << "\n";
    //cout << x + (k*(b/g)) << "\n";
    return (x + (k*(b/g)) >= 0) && (y - (k*(a/g)) >= 0);
}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int c;
        scanf(" %d",&c);
        if(findAny(2020,2021,c))
            puts("YES");
        else puts("NO");
    }
    return 0;
}
