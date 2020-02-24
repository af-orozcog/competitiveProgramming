#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf(" %d",&n);
    int posi = 1;
    for(int i = 0; i < n;++i){
        int va;scanf(" %d",&va);
        if(va%3 && va%5 && (va%2 == 0)) posi = 0;
    }
    if(posi)
        puts("APPROVED");
    else
        puts("DENIED");
    return 0;
}
