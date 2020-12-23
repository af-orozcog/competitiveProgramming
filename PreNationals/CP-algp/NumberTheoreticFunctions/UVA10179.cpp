#include<bits/stdc++.h>
using namespace std;

int phi(int n){
    int answer =  n;
    int upTo = sqrt(n);
    for(int i = 2; i <= upTo;++i){
        if(n % i == 0){
            while(n % i == 0)
                n /= i;
            answer -= answer/i;
        }
    }
    if(n > 1)
        answer -= answer/n;
    return answer;
}


int main(){
    int n;
    while(scanf(" %d",&n) && n){
        printf("%d\n",phi(n));
    }
    return 0;
}
