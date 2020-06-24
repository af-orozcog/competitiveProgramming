//hope to have a good performance to show Marie :)
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        priority_queue<pair<int,pi>> q;
        q.push({n,{0,-1*(n-1)}});
        int ans[n];
        int i = 1;
        while(i <= n){
            pair<int,pi> see = q.top();
            q.pop();
            see.second.first *= -1;
            see.second.second *= -1;
            int pa = (see.second.first + see.second.second)/2;
            ans[pa] = i++;
            int le = pa - see.second.first;
            int ri = see.second.second - pa;
            q.push({le,{-see.second.first,-1*(pa-1)}});
            q.push({ri,{-1*(pa+1),-see.second.second}});
        }
        for(int i = 0; i < n;++i) printf("%d ",ans[i]);
        puts("");
    }
    return 0;
}
