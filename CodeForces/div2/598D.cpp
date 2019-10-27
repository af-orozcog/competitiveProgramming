    #include<iostream>
    #include<queue>
     
    using namespace std;
     
    int matrix[1000][1000];
    int movesX[] = {1,-1,0,0};
    int movexY[] = {0,0,-1,1};
     
    queue<pair<int,int>> mov;
    int move(int x, int y, int n,int m){
        if(x < 0 || x >= n || y < 0 || y >= m)
            return 0;
        if(matrix[x][y] == -2)
            return 0;
        if(matrix[x][y] == -1)
            return 1;
        matrix[x][y] = -2;
        mov.push({x,y});
        int ans = 0;
        for(int i = 0; i < 4;++i)
            ans += move(x+movesX[i],y+movexY[i],n,m);
        return ans;
    }
     
    int main(){
        int n,m,q;
        scanf(" %d %d %d",&n,&m,&q);
        for(int i = 0; i < n;++i){
            for(int j = 0; j < m;++j){
                char va;
                scanf(" %c",&va);
                matrix[i][j] = (va == '*'? -1:0);
            }
        }
        while(q--){
            int a,b;
            scanf(" %d %d",&a,&b);
            --a;--b;
            if(matrix[a][b] != 0)
                printf("%d\n",matrix[a][b]);
            else{
                int val = move(a,b,n,m);
                while(mov.size()){
                    matrix[mov.front().first][mov.front().second] = val;
                    mov.pop();
                }
                printf("%d\n",val);
            }
        }
        return 0;
    }