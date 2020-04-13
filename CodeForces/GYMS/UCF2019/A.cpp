#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,d;
    scanf(" %d %d",&n,&d);
    int ar[n];
    int sum = 0;
    for(int i = 0; i < n;++i){
        scanf(" %d",&ar[i]);
        sum += ar[i];
    }
    int per = d/sum;
    for(int i = 0; i < n;++i)
        printf("%d\n",per*ar[i]);
    return 0;
}
