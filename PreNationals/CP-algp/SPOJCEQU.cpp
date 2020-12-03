#include<bits/stdc++.h>
using namespace std;

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

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}



int main(){
    int t;
    scanf(" %d",&t);
    int cas = 1;
    while(t--){
        int a,b,c;
        scanf(" %d %d %d",&a,&b,&c);
        int x0,y0,g;
        printf("Case %d: ",cas++);
        if(find_any_solution(a,b,c,x0,y0,g))
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
