#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    scanf(" %d %d",&n,&m);
    int sum = 0;
    for(int i = 0; i < m;++i){
        int va; scanf(" %d",&va);
        sum += va;
    }
    if(sum > n)puts("-1");
    else printf("%d\n",n-sum);
    return 0;
}
