#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    int check = a*b*2;
    int p = b, q = a;
    while(a != b){
        if(a < b){
            swap(a,b);
            swap(p,q);
        }
        a -= b;
        q += p;
        if(a*p + b*q != check) return -1;
    }
    return a;
}


int main(){
    int a,b;
    scanf(" %d %d",&a,&b);
    printf("%d\n",gcd(a,b));
    return 0;
}
