#include<bits/stdc++.h>
using namespace std;

int multi(int a, int b){
    if(!a) return 0;
    int ans = 2*multi(a/2,b);
    if(a&1) ans += b;
    cout << a << " " << b << " " << "\n";
    return ans;
}


int multiIte(int a, int b){
    int ans = 0;
    int temp = b;
    while(a){
        if(a&1) ans += temp;
        temp <<= 1;
        a >>= 1;
    }
    return ans;
}

int main(){
    int a,b;
    scanf(" %d %d",&a,&b);
    printf("%d\n",multiIte(a,b));
    return 0;
}
