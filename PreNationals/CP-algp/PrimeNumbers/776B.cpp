#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    int upTo = sqrt(n);
    for(int i = 2; i <= upTo;++i){
        if(n % i == 0) return false;
    }
    return true;
}


int main(){
    int n;
    scanf(" %d",&n);
    if(n > 2) puts("2");
    else{
        if(n == 1) puts("1\n1");
        else puts("1\n1 1");
        return 0;
    }
    for(int i = 2; i <= n+1;++i){
        if(isPrime(i)) printf("1 ");
        else printf("2 ");
    }
    puts("");
}
