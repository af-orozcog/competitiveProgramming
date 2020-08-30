#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    scanf(" %d %d",&n,&m);
    int seen[30000];
    if(n > m){
        printf("%d\n",n-m);
        return 0;
    }
    memset(seen,-1,sizeof(seen));
    queue<int> q;
    q.push(n);
    seen[n] = 0;
    while(q.size() && seen[m] == -1){
        int dad = q.front();
        q.pop();
        int son1 = dad-1,son2 = dad<<1;
        if(son1 > 0 && seen[son1] == -1){
            seen[son1] = seen[dad]+1;
            q.push(son1);
        }
        if(son2 < 30000 && seen[son2] == -1){
            seen[son2] = seen[dad]+1;
            q.push(son2);
        }
    }
    printf("%d\n",seen[m]);
    return 0;
}
