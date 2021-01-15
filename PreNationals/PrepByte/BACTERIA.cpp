#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

int main(){
    int n,m;
    scanf(" %d %d",&n,&m);
    queue<pi> q;
    q.push({m,0});
    int ans = -1;
    while(q.size()){
        pi dad = q.front();
        q.pop();
        if(dad.first < n) continue;
        if(dad.first == n){
            ans = dad.second;
            break;
        }
        if(dad.first % 3 == 0)
            q.push({dad.first/3,dad.second+1});
        if(dad.first % 2 == 0)
            q.push({dad.first/2,dad.second+1});
    }
    printf("%d\n",ans);
}
