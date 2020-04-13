#include<bits/stdc++.h>
#define MAX 100006
using namespace std;


int UF[MAX],cou[MAX];

int search(int x){
    return UF[x] == x ? x: (UF[x] = search(UF[x]));
}

bool connected(int x, int y){
    return search(x) == search(y);
}

void connect(int x, int y){
    int dadX = search(x), dadY = search(y);
    if(dadX != dadY){
        UF[dadX] = dadY;
        cou[dadY] += cou[dadX];
    }
}

int main(){
    for(int i = 0; i < MAX;++i){
        UF[i] = i;
        cou[i] = 1;
    }
    int n,m,k;
    scanf(" %d %d %d",&n,&m,&k);
    vector<int> ans(n,0);
    vector<int> fr(n,0);
    vector<set<int>> enemies(n);
    while(m--){
        int a,b;
        scanf(" %d %d",&a,&b);
        --a,--b;
        connect(a,b);
        ++fr[a];
        ++fr[b];
    }
    while(k--){
        int a,b;
        scanf(" %d %d",&a,&b);
        --a,--b;
        enemies[a].insert(b);
        enemies[b].insert(a);
    }
    for(int i = 0; i < n;++i){
        ans[i] += cou[search(i)];
        for(auto ve:enemies[i]){
            if(connected(i,ve)){
                --ans[i];
                --ans[ve];
            }
            enemies[ve].erase(i);
        }
        if(i == 0) printf("%d",ans[i]-fr[i]-1);
        else printf(" %d",ans[i]-fr[i]-1);
    }
    puts("");
    return 0;
}
