#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){
    int a,b,c;
    scanf(" %d %d %d",&a,&b,&c);
    if(c == 0){
        if(a > b) puts("Takahashi");
        else puts("Aoki");
    }
    else{
        if(b > a)puts("Aoki");
        else puts("Takahashi");
    }
    return 0;
}
