#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int ar[2];
        scanf(" %d %d",&ar[0],&ar[1]);
        sort(ar,ar+2);
        int add = ar[1]-(2*ar[0]);
        //cout << add << "\n";
        ar[0]= ar[0]<<1;
        if(add<0) ar[1] -=add;
        else ar[0] += add;
        printf("%d\n",(ar[0]*ar[1]));
    }
    return 0;
}
