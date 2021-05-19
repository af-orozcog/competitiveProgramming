#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){
    int a,b,c;
    scanf(" %d %d %d",&a,&b,&c);
    if(a*a + b*b < c*c) puts("Yes");
    else puts("No");
    return 0;
}
