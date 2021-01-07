#include<bits/stdc++.h>
using namespace std;


int UF[5000];
int sz[5000];

int search(int x){
    return UF[x] == x? x: (UF[x] = search(UF[x]));
}

void connect(int x, int y){
    int dadX = search(x),dadY = search(y);
    if(dadX != dadY){
        sz[dadX] += sz[dadY];
        UF[dadY] = dadX;
    }
}

int main(){
    int n,c;
    while(1){
        scanf(" %d %d",&n,&c);
        if(n == c && n == 0) break;
        for(int i = 0; i < n;++i){
            UF[i] = i;
            sz[i] = 1;
        }
        unordered_map<string,int> tr;
        string temp;
        for(int i = 0; i < n;++i){
            cin >> temp;
            tr[temp] = i;
        }
        while(c--){
            string from,to;
            cin >> from >> to;
            connect(tr[from],tr[to]);
        }
        int ans = 0;
        for(int i = 0; i < n;++i)
            ans = max(ans,sz[i]);
        printf("%d\n",ans);
    }
    return 0;
}
