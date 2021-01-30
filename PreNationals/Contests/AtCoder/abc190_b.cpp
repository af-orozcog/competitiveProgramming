#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int main(){
    int n,s,d;
    scanf(" %d %d %d",&n,&s,&d);
    bool ans = 0;
    while(n--){
        int x,y;
        scanf(" %d %d",&x,&y);
        ans = ans | (x < s && y > d);
    }
    if(ans) puts("Yes");
    else puts("No");
    return 0;
}
