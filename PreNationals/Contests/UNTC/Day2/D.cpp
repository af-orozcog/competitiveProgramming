#include<bits/stdc++.h>
using namespace std;

int inf = INT_MAX;

int lg2[100000];
int K = 12;
int st[13][501][13][501];

int query(int x, int y, int sz){
    int imp = lg2[sz];
    int X = x + sz-1;
    int Y = y + sz-1;
    int see1 = st[imp][x][imp][y];
    int see2 = st[imp][X][imp][Y - (1<<imp)+1];
    int see3 = st[imp][X-(1<<imp)+1][imp][y];
    int see4 = st[imp][X-(1<<imp)+1][imp][Y-(1<<imp)+1];
    return max( max(st[imp][x][imp][y], st[imp][x][imp][Y - (1<<imp)+1]),
                max(st[imp][X-(1<<imp)+1][imp][y],st[imp][X-(1<<imp)+1][imp][Y-(1<<imp)+1])
    );
}

int main(){
    for(int i = 2; i < 100000;++i)
        lg2[i] = lg2[i>>1] +1;
    int n,m,k,q;
    scanf(" %d %d %d %d",&n,&m,&k,&q);
    for(int i = 0; i <= K;++i){
        for(int j = 0; j < n;++j){
            for(int k = 0; k <= K;++k){
                for(int w = 0; w < m;++w)
                    st[i][j][k][w] = inf;
            }
        }
    }
    while(q--){
        int x,y,t;
        scanf(" %d %d %d",&x,&y,&t);
        --x,--y;
        st[0][x][0][y] = t;
    }

    for(int r = 0; r < n;++r){
        for(int j = 1; j <= K;++j){
            for(int i = 0; i+(1<<j) <= m;++i){
                st[0][r][j][i] = max(st[0][r][j-1][i],st[0][r][j-1][i+(1<<(j-1))]);
                int see = st[0][r][j][i];
            }
        }
    }
    for(int i = 1; i <= K;++i){
        for(int j = 0; j+(1<<i) <= n;++j){
            for(int p = 1; p <= K;++p){
                for(int q = 0; q+(1<<p) <= m;++q){
                    st[i][j][p][q] = max(max(st[i-1][j+(1<<(i-1))][p-1][q],st[i-1][j+(1<<(i-1))][p-1][q + (1 << (p-1))]),
                                         max(st[i-1][j][p-1][q],st[i-1][j][p-1][q + (1 << (p-1))]));
                    int see = st[i][j][p][q];
                }
            }
        }
    }
    int ans = inf;

    for(int i = 0; i+k-1 < n;++i){
        for(int j = 0; j+k-1 < m;++j){
            ans = min(ans,query(i,j,k));
        }
    }

    if(ans == inf)puts("-1");
    else printf("%d\n",ans);
    return 0;
}
