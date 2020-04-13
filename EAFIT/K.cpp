#include<bits/stdc++.h>
using namespace std;

int UF[50002];

int search(int x){
    return UF[x] == x? x: (UF[x] = search(UF[x]));
}

void connect(int x, int y){
    int dadX = search(x),dadY = search(y);
    if(dadX != dadY)
        UF[dadX] = dadY;
}

int main(){
    int n,m;
    int ca = 1;
    while(scanf(" %d %d",&n,&m) && (n!= 0 && m != 0)){
        for(int i = 0; i < n;++i) UF[i] = i;
        while(m--){
            int a,b;
            scanf(" %d %d",&a,&b);
            connect(a,b);
        }
        set<int> dif;
        for(int i = 0; i < n;++i) dif.insert(search(i));
        printf("Case %d: %d\n",ca++,(int)dif.size());
    }
    return 0;
}
