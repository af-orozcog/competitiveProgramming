#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){
    int n,x,y;
    scanf(" %d %d %d",&n,&x,&y);
    set<pi> imp = {{n/2,n/2},{n/2+1,n/2},{n/2,n/2+1},{n/2+1,n/2+1}};
    if(imp.count({x,y})) puts("NO");
    else puts("YES");
    return 0;
}
