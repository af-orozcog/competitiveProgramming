#include<bits/stdc++.h>
using namespace std;

vector<int> UF;
vector<int> enemies;

int search(int x){
    return UF[x] == x ? x: (UF[x] = search(UF[x]));
}

bool connected(int x, int y){
    return search(x) == search(y);
}

void connect(int x, int y){
    int dadX = search(x),dadY = search(y);
    if(dadX != dadY){
        if(enemies[dadX] != -1){
            UF[dadY] = dadX;
            if(enemies[dadY] != -1) connect(enemies[dadX],enemies[dadY]);
        }
        else if(enemies[dadY] != -1)
            UF[dadX] = dadY;
        else UF[dadY] = dadX;
    }
}

bool canBeConnected(int a, int b){
    if(a == -1 || b == -1) return 1;
    int enemy1 = enemies[search(a)];
    int enemy2 = enemies[search(b)];
    if(enemy1 != -1 && connected(enemy1,b)) return 0;
    if(enemy2 != -1 && connected(enemy2,a)) return 0;
    connect(a,b);
    if(enemy1 != -1 && enemy2 != -1) connect(enemy1,enemy2);
    return 1;
}


int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        UF.clear(); enemies.clear();
        int n,k;
        scanf(" %d %d",&n,&k);
        UF.resize(n); enemies.resize(n,-1);
        for(int i = 0; i < n;++i) UF[i] = i;
        int ans = 0;
        while(k--){
            int d,a,b;
            scanf(" %d %d %d",&d,&a,&b);
            --a,--b;
            if(a >= n || b >= n){++ans;continue;}
            else if(d == 1)
                ans += !canBeConnected(a,b);
            else{
                if(connected(a,b))++ans;
                else if(enemies[search(a)] == -1) enemies[search(a)] = b;
                else ans += !canBeConnected(enemies[search(a)],b);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
