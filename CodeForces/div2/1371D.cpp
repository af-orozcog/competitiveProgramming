#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,k;
        scanf("%d %d",&n,&k);
        int matrix[n][n];
        memset(matrix,0,sizeof(matrix));
        int x[2][2] = {{0,1},{n-1,n-1}};
        int y[2][2] = {{0,0},{n-1,n-2}};
        int turn = 0;
        while(k){
            int xf = x[0][turn],xt = x[1][turn];
            int yf = y[0][turn],yt = y[1][turn];
            while(k && xf <= xt){
                matrix[xf][yf] = 1;
                --k;
                if(!k || xf == xt)break;
                matrix[xt][yt] = 1;
                ++xf,++yf,--xt,--yt;
                --k;
            }
            if(turn)
                ++x[0][turn],--y[1][turn];
            else
                ++y[0][turn],--x[1][turn];
            turn += 1;
            turn = turn&1;
        }
        int miC = 1000000000, maC = 0;
        for(int i = 0; i < n;++i){
            int sum = 0;
            for(int j = 0; j < n;++j)
                sum += matrix[j][i];
            maC = max(sum,maC);
            miC = min(miC,sum);
        }
        int miR = 1000000000, maR = 0;
        for(int i = 0; i < n;++i){
            int sum = 0;
            for(int j = 0; j < n;++j)
                sum += matrix[i][j];
            maR = max(sum,maR);
            miR = min(miR,sum);
        }
        int show = (maR-miR)*(maR-miR) + (maC-miC)*(maC-miC);
        printf("%d\n",show);
        for(int i = 0; i < n;++i){
            for(int j = 0; j < n;++j)
                printf("%d",matrix[i][j]);
            puts("");
        }
    }
    return 0;
}
